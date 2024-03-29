#include "connect2csharp.h"


// this class works only for planning (and not for exporting eulynx)
Connect2CSharp::Connect2CSharp(QByteArray mdbFilePath, QByteArray kmLinePath, QByteArray gleiskantenPath,
                               QByteArray gleisknotenPath, QByteArray hoehePath, QByteArray UH_Path,
                               QByteArray LA_Path, QByteArray outputPath)
{
    this->mdbFilePath = mdbFilePath;
    this->kmLinePath = kmLinePath;
    this->gleiskantenPath = gleiskantenPath;
    this->gleisknotenPath = gleisknotenPath;
    this->hoehePath = hoehePath;
    this->UH_Path = UH_Path;
    this->LA_Path = LA_Path;
    this->outputPath = outputPath;
    this->isFinishedRunning = false;

}

void Connect2CSharp::cSharp()
{
    csharp = new QProcess(this);
    findOS();   //determine the operating system

    connect(csharp, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished), this, &Connect2CSharp::planningFinished);
//    connect(csharp, &QProcess::started, this, &Connect2CSharp::planningFinished);

    // replace this with corresponding filepath
    QString filePath = "APLAN-CORE.exe";
    csharp->start(filePath);
    if(!csharp->waitForStarted(3000)) {
        this->isAvailable = false;
        qInfo()<< "Problem with opening of APlan_Core App \n "
                  "... some linking file(s) are missing. Please contact your administrator";
        return;
    }

    // write data(each parameter) to the terminal, followed by Enter key
    if(!state.endsWith(endl.toLatin1())) state.append(endl.toUtf8());
    csharp->write(state);
    csharp->waitForBytesWritten(1000);

    QByteArray Code = countryCode.toUtf8();
    QByteArray format = fileFormat.toUtf8();
    QByteArray name = projectName.toUtf8();

    if(!Code.endsWith(endl.toLatin1())) Code.append(endl.toUtf8());
    csharp->write(Code);
    csharp->waitForBytesWritten(1000);

    if(!format.endsWith(endl.toLatin1())) format.append(endl.toUtf8());
    csharp->write(format);
    csharp->waitForBytesWritten(1000);

    if(!name.endsWith(endl.toLatin1())) name.append(endl.toUtf8());
    csharp->write(name);
    csharp->waitForBytesWritten(1000);

    if (fileFormat == ".mdb"){
        qDebug()<< "Temporary disabled for mdb data";
        csharp->closeWriteChannel();
        return;

    } else if(fileFormat == ".json"){
        if(!kmLinePath.endsWith(endl.toLatin1())) kmLinePath.append(endl.toUtf8());
        csharp->write(kmLinePath);
        csharp->waitForBytesWritten(1000);

        if(!gleiskantenPath.endsWith(endl.toLatin1())) gleiskantenPath.append(endl.toUtf8());
        csharp->write(gleiskantenPath);
        csharp->waitForBytesWritten(1000);

        if(!gleisknotenPath.endsWith(endl.toLatin1())) gleisknotenPath.append(endl.toUtf8());
        csharp->write(gleisknotenPath);
        csharp->waitForBytesWritten(1000);

        if(!hoehePath.endsWith(endl.toLatin1())) hoehePath.append(endl.toUtf8());
        csharp->write(hoehePath);
        csharp->waitForBytesWritten(1000);

        if(!UH_Path.endsWith(endl.toLatin1())) UH_Path.append(endl.toUtf8());
        csharp->write(UH_Path);
        csharp->waitForBytesWritten(1000);

        if(!LA_Path.endsWith(endl.toLatin1())) LA_Path.append(endl.toUtf8());
        csharp->write(LA_Path);
        csharp->waitForBytesWritten(1000);

        if(!outputPath.endsWith(endl.toLatin1())) outputPath.append(endl.toUtf8());
        csharp->write(outputPath);
        csharp->waitForBytesWritten(1000);

        csharp->closeWriteChannel();
    }else {
        qDebug()<< "Please import valid file format (.json, .geojson)";
    }
}

const QString &Connect2CSharp::getAntwort() const
{
    return antwort;
}

void Connect2CSharp::setAntwort(const QString &newAntwort)
{
    antwort = newAntwort;
}

QStringList Connect2CSharp::solutionsList()
{
    qDebug() << "Antwort: " << getAntwort();
    QStringList sol1;   // temporary container
    QStringList sol = this->getAntwort().split(QRegularExpression("\\n"), Qt::SkipEmptyParts);

    foreach(QString value, sol){
        sol1.append(value.remove('\r')); //    replace('\r',""));
    }
    int count =0;
    for (int i=0; i<=sol1.length(); i++){
        if (sol1[i] == "DB_NETZ"){
            count = count + 1;
            break;
        }
        count++;
    }
    sol.clear();
    for (int i = count; i< sol1.length(); i++){
            sol.append(sol1[i]);
    }
    sol1.clear();
    for (int j =0; j< sol.length(); j++){
        if (!sol[j].isNull() && !sol[j].isEmpty()){
            sol1.append(sol[j]);
        }
    }
    return sol1;
}

void Connect2CSharp::mainSolution()
{
    QStringList sol = solutionsList();
    int rows = sol.length()/5;
    int cols = 5;
    QString** table = new QString*[rows];
    for(int i = 0; i<rows; i++){
        table[i] = new QString[cols];
    }
    int count =0;
    for(int i = 0; i<rows; i++){
        for (int j=0; j<cols; j++){
            table[i][j] = sol[count];
            count++;
        }
    }
    this->setNumberOfRows(rows);
    this->setNumberofCols(cols);
    this->setMainAntwort(table);
}


QString **Connect2CSharp::getMainAntwort() const
{
    return mainAntwort;
}

void Connect2CSharp::setMainAntwort(QString **newMainAntwort)
{
    mainAntwort = newMainAntwort;
}

int Connect2CSharp::getNumberOfRows() const
{
    return NumberOfRows;
}

void Connect2CSharp::setNumberOfRows(int newNumberOfRows)
{
    NumberOfRows = newNumberOfRows;
}

int Connect2CSharp::getNumberofCols() const
{
    return NumberofCols;
}

void Connect2CSharp::setNumberofCols(int newNumberofCols)
{
    NumberofCols = newNumberofCols;
}

void Connect2CSharp::planningFinished(int exitCode, QProcess::ExitStatus exitStatus)
{
    Q_UNUSED(exitStatus);
    Q_UNUSED(exitCode);
    QByteArray result = csharp->readAll();
    this->setAntwort(result);
    this->setIsFinishedRunning(true);
}

bool Connect2CSharp::getIsFinishedRunning() const
{
    return isFinishedRunning;
}

void Connect2CSharp::setIsFinishedRunning(bool newIsFinishedRunning)
{
    isFinishedRunning = newIsFinishedRunning;
}

void Connect2CSharp::findOS()
{
    // Linux
    this->setApp("bash");
    this->setEndl("\n");
#ifdef Q_OS_WIN
    //Windows
    this->setApp("cmd");
    this->setEndl("\n");
//    this->setEndl("\r\n");

#elif Q_OS_MACOS
    //Mac
    this->setApp("zsh");
    this->setEndl("\n");
#endif
}

const QString &Connect2CSharp::getApp() const
{
    return app;
}

void Connect2CSharp::setApp(const QString &newApp)
{
    app = newApp;
}

const QString &Connect2CSharp::getEndl() const
{
    return endl;
}

void Connect2CSharp::setEndl(const QString &newEndl)
{
    endl = newEndl;
}

