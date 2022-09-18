/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qgraphicsmainwindow.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionNew_2;
    QAction *actionSave_As;
    QAction *actionPrint;
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *actionExit;
    QAction *actionAdd_symbol;
    QAction *actionAdd_symbol_options;
    QAction *actionAdd_Data;
    QAction *actionPreview_Data;
    QAction *actionRemove_Data;
    QAction *actionImport;
    QAction *actionUndo_2;
    QAction *actionRedo_2;
    QAction *actionXML_Json;
    QAction *actionDelete_Items;
    QAction *actionSelection_Mode;
    QAction *actionEULYNX_Validator;
    QAction *actionPlanning_Tab;
    QAction *actionText;
    QAction *actionAbout_Qt;
    QAction *actionDark_Theme;
    QAction *actionLight_Rules;
    QAction *actionOSM;
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QFrame *f_headerTabs;
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *f_planning;
    QGridLayout *gridLayout_129;
    QFrame *frame_130;
    QHBoxLayout *horizontalLayout_44;
    QFrame *frame_145;
    QVBoxLayout *verticalLayout_117;
    QFrame *frame_147;
    QGridLayout *gridLayout_147;
    QWidget *widget_149;
    QGridLayout *gridLayout_148;
    QPushButton *pushButton_77;
    QFrame *frame_146;
    QGridLayout *gridLayout_149;
    QLabel *label_47;
    QFrame *line_18;
    QFrame *frame_132;
    QGridLayout *gridLayout_131;
    QFrame *frame_134;
    QGridLayout *gridLayout_132;
    QLabel *label_46;
    QFrame *frame_133;
    QGridLayout *gridLayout_133;
    QWidget *widget_148;
    QGridLayout *gridLayout_130;
    QPushButton *planBtn;
    QComboBox *cmbPlan;
    QFrame *line_19;
    QFrame *frame_4;
    QGridLayout *gridLayout_13;
    QWidget *widget_72;
    QGridLayout *gridLayout_18;
    QWidget *widget_150;
    QVBoxLayout *verticalLayout_125;
    QWidget *widget_152;
    QGridLayout *gridLayout_20;
    QPushButton *exportBtnPlan;
    QWidget *widget_153;
    QGridLayout *gridLayout_19;
    QComboBox *cmbExport;
    QLabel *label_44;
    QFrame *line_16;
    QFrame *frame_7;
    QGridLayout *gridLayout_58;
    QWidget *widget_145;
    QGridLayout *gridLayout_59;
    QPushButton *btnSymbol;
    QLabel *label_41;
    QFrame *line_20;
    QFrame *frame_52;
    QGridLayout *gridLayout_122;
    QWidget *widget_154;
    QGridLayout *gridLayout_125;
    QPushButton *grabBtn_2;
    QLabel *label_48;
    QSpacerItem *horizontalSpacer_3;
    QFrame *f_openGl;
    QHBoxLayout *horizontalLayout_31;
    QWidget *widget_146;
    QGridLayout *gridLayout_69;
    QTableWidget *tableWidget;
    QWidget *widget_30;
    QGridLayout *gridLayout_14;
    QTabWidget *tabWidget_2;
    QWidget *tab_2;
    QGridLayout *gridLayout_8;
    QLabel *label_43;
    QWidget *tab_4;
    QGridLayout *gridLayout_17;
    QWidget *widget_151;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_126;
    QGraphicsMainWindow *widget_142;
    QWidget *tab;
    QWidget *widget_147;
    QGridLayout *gridLayout_70;
    QLabel *lblTrackName;
    QTableWidget *tableWidget_2;
    QMenuBar *menubar;
    QMenu *menuNew;
    QMenu *menuEdit;
    QMenu *menuTools;
    QMenu *menuAccess_Data;
    QMenu *menuView;
    QMenu *menuGrid_Style;
    QMenu *menuHelp;
    QStatusBar *statusbar;
    QToolBar *toolBar;
    QToolBar *viewToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(2187, 726);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/assets/home/eulynx.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        actionNew->setEnabled(false);
        actionNew->setVisible(false);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/assets/folder.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon1);
        actionOpen->setIconVisibleInMenu(true);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/assets/menubar/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon2.addFile(QString::fromUtf8(":/icons/assets/menubar/save.png"), QSize(), QIcon::Normal, QIcon::On);
        actionSave->setIcon(icon2);
        actionNew_2 = new QAction(MainWindow);
        actionNew_2->setObjectName(QString::fromUtf8("actionNew_2"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/assets/menubar/new.png"), QSize(), QIcon::Normal, QIcon::On);
        actionNew_2->setIcon(icon3);
        actionSave_As = new QAction(MainWindow);
        actionSave_As->setObjectName(QString::fromUtf8("actionSave_As"));
        actionSave_As->setCheckable(false);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/assets/menubar/saveas.png"), QSize(), QIcon::Normal, QIcon::On);
        actionSave_As->setIcon(icon4);
        actionPrint = new QAction(MainWindow);
        actionPrint->setObjectName(QString::fromUtf8("actionPrint"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icons/assets/menubar/print.png"), QSize(), QIcon::Normal, QIcon::On);
        actionPrint->setIcon(icon5);
        actionUndo = new QAction(MainWindow);
        actionUndo->setObjectName(QString::fromUtf8("actionUndo"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icons/assets/menubar/undo.png"), QSize(), QIcon::Normal, QIcon::On);
        actionUndo->setIcon(icon6);
        actionRedo = new QAction(MainWindow);
        actionRedo->setObjectName(QString::fromUtf8("actionRedo"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/icons/assets/menubar/redo.png"), QSize(), QIcon::Normal, QIcon::On);
        actionRedo->setIcon(icon7);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionAdd_symbol = new QAction(MainWindow);
        actionAdd_symbol->setObjectName(QString::fromUtf8("actionAdd_symbol"));
        actionAdd_symbol_options = new QAction(MainWindow);
        actionAdd_symbol_options->setObjectName(QString::fromUtf8("actionAdd_symbol_options"));
        actionAdd_Data = new QAction(MainWindow);
        actionAdd_Data->setObjectName(QString::fromUtf8("actionAdd_Data"));
        actionPreview_Data = new QAction(MainWindow);
        actionPreview_Data->setObjectName(QString::fromUtf8("actionPreview_Data"));
        actionRemove_Data = new QAction(MainWindow);
        actionRemove_Data->setObjectName(QString::fromUtf8("actionRemove_Data"));
        actionImport = new QAction(MainWindow);
        actionImport->setObjectName(QString::fromUtf8("actionImport"));
        actionImport->setEnabled(false);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/icons/assets/Plan/icons8-import-48.png"), QSize(), QIcon::Normal, QIcon::On);
        actionImport->setIcon(icon8);
        actionUndo_2 = new QAction(MainWindow);
        actionUndo_2->setObjectName(QString::fromUtf8("actionUndo_2"));
        actionUndo_2->setEnabled(false);
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/icons/assets/menubar/undo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionUndo_2->setIcon(icon9);
        actionRedo_2 = new QAction(MainWindow);
        actionRedo_2->setObjectName(QString::fromUtf8("actionRedo_2"));
        actionRedo_2->setEnabled(false);
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/icons/assets/menubar/redo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRedo_2->setIcon(icon10);
        actionXML_Json = new QAction(MainWindow);
        actionXML_Json->setObjectName(QString::fromUtf8("actionXML_Json"));
        actionDelete_Items = new QAction(MainWindow);
        actionDelete_Items->setObjectName(QString::fromUtf8("actionDelete_Items"));
        actionSelection_Mode = new QAction(MainWindow);
        actionSelection_Mode->setObjectName(QString::fromUtf8("actionSelection_Mode"));
        actionSelection_Mode->setCheckable(true);
        actionEULYNX_Validator = new QAction(MainWindow);
        actionEULYNX_Validator->setObjectName(QString::fromUtf8("actionEULYNX_Validator"));
        actionPlanning_Tab = new QAction(MainWindow);
        actionPlanning_Tab->setObjectName(QString::fromUtf8("actionPlanning_Tab"));
        actionPlanning_Tab->setCheckable(true);
        actionPlanning_Tab->setChecked(false);
        actionText = new QAction(MainWindow);
        actionText->setObjectName(QString::fromUtf8("actionText"));
        actionText->setCheckable(true);
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/icons/assets/home/text.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionText->setIcon(icon11);
        actionAbout_Qt = new QAction(MainWindow);
        actionAbout_Qt->setObjectName(QString::fromUtf8("actionAbout_Qt"));
        actionDark_Theme = new QAction(MainWindow);
        actionDark_Theme->setObjectName(QString::fromUtf8("actionDark_Theme"));
        actionDark_Theme->setCheckable(true);
        actionDark_Theme->setChecked(true);
        actionLight_Rules = new QAction(MainWindow);
        actionLight_Rules->setObjectName(QString::fromUtf8("actionLight_Rules"));
        actionLight_Rules->setCheckable(true);
        actionLight_Rules->setChecked(false);
        actionOSM = new QAction(MainWindow);
        actionOSM->setObjectName(QString::fromUtf8("actionOSM"));
        actionOSM->setEnabled(true);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        f_headerTabs = new QFrame(centralwidget);
        f_headerTabs->setObjectName(QString::fromUtf8("f_headerTabs"));
        f_headerTabs->setEnabled(true);
        sizePolicy.setHeightForWidth(f_headerTabs->sizePolicy().hasHeightForWidth());
        f_headerTabs->setSizePolicy(sizePolicy);
        f_headerTabs->setMinimumSize(QSize(0, 0));
        f_headerTabs->setMaximumSize(QSize(16777215, 140));
        f_headerTabs->setLayoutDirection(Qt::LeftToRight);
        f_headerTabs->setFrameShape(QFrame::NoFrame);
        f_headerTabs->setFrameShadow(QFrame::Plain);
        horizontalLayout = new QHBoxLayout(f_headerTabs);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(f_headerTabs);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMaximumSize(QSize(16777215, 150));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(widget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setEnabled(true);
        tabWidget->setMaximumSize(QSize(16777215, 150));
        QFont font;
        font.setKerning(true);
        tabWidget->setFont(font);
        tabWidget->setMouseTracking(true);
        tabWidget->setAutoFillBackground(true);
        tabWidget->setIconSize(QSize(10, 10));
        tabWidget->setUsesScrollButtons(true);
        tabWidget->setDocumentMode(false);
        tabWidget->setTabsClosable(true);
        tabWidget->setMovable(true);
        tabWidget->setTabBarAutoHide(false);
        f_planning = new QWidget();
        f_planning->setObjectName(QString::fromUtf8("f_planning"));
        gridLayout_129 = new QGridLayout(f_planning);
        gridLayout_129->setSpacing(0);
        gridLayout_129->setObjectName(QString::fromUtf8("gridLayout_129"));
        gridLayout_129->setContentsMargins(0, 0, 0, 0);
        frame_130 = new QFrame(f_planning);
        frame_130->setObjectName(QString::fromUtf8("frame_130"));
        frame_130->setFrameShape(QFrame::StyledPanel);
        frame_130->setFrameShadow(QFrame::Raised);
        horizontalLayout_44 = new QHBoxLayout(frame_130);
        horizontalLayout_44->setObjectName(QString::fromUtf8("horizontalLayout_44"));
        frame_145 = new QFrame(frame_130);
        frame_145->setObjectName(QString::fromUtf8("frame_145"));
        frame_145->setMinimumSize(QSize(61, 0));
        frame_145->setFrameShape(QFrame::StyledPanel);
        frame_145->setFrameShadow(QFrame::Raised);
        verticalLayout_117 = new QVBoxLayout(frame_145);
        verticalLayout_117->setSpacing(0);
        verticalLayout_117->setObjectName(QString::fromUtf8("verticalLayout_117"));
        verticalLayout_117->setContentsMargins(0, 0, 0, 0);
        frame_147 = new QFrame(frame_145);
        frame_147->setObjectName(QString::fromUtf8("frame_147"));
        frame_147->setFrameShape(QFrame::StyledPanel);
        frame_147->setFrameShadow(QFrame::Raised);
        gridLayout_147 = new QGridLayout(frame_147);
        gridLayout_147->setSpacing(0);
        gridLayout_147->setObjectName(QString::fromUtf8("gridLayout_147"));
        gridLayout_147->setContentsMargins(0, 0, 0, 0);
        widget_149 = new QWidget(frame_147);
        widget_149->setObjectName(QString::fromUtf8("widget_149"));
        gridLayout_148 = new QGridLayout(widget_149);
        gridLayout_148->setObjectName(QString::fromUtf8("gridLayout_148"));
        pushButton_77 = new QPushButton(widget_149);
        pushButton_77->setObjectName(QString::fromUtf8("pushButton_77"));
        pushButton_77->setStyleSheet(QString::fromUtf8("border:none;"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/icons/assets/Plan/import.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_77->setIcon(icon12);
        pushButton_77->setIconSize(QSize(30, 30));

        gridLayout_148->addWidget(pushButton_77, 0, 0, 1, 1);


        gridLayout_147->addWidget(widget_149, 0, 0, 1, 1);


        verticalLayout_117->addWidget(frame_147);

        frame_146 = new QFrame(frame_145);
        frame_146->setObjectName(QString::fromUtf8("frame_146"));
        frame_146->setMinimumSize(QSize(0, 20));
        frame_146->setMaximumSize(QSize(16777215, 20));
        frame_146->setFrameShape(QFrame::StyledPanel);
        frame_146->setFrameShadow(QFrame::Raised);
        gridLayout_149 = new QGridLayout(frame_146);
        gridLayout_149->setSpacing(0);
        gridLayout_149->setObjectName(QString::fromUtf8("gridLayout_149"));
        gridLayout_149->setContentsMargins(0, 0, 0, 0);
        label_47 = new QLabel(frame_146);
        label_47->setObjectName(QString::fromUtf8("label_47"));
        label_47->setAlignment(Qt::AlignCenter);

        gridLayout_149->addWidget(label_47, 0, 0, 1, 1);


        verticalLayout_117->addWidget(frame_146);


        horizontalLayout_44->addWidget(frame_145);

        line_18 = new QFrame(frame_130);
        line_18->setObjectName(QString::fromUtf8("line_18"));
        line_18->setFrameShadow(QFrame::Raised);
        line_18->setFrameShape(QFrame::VLine);

        horizontalLayout_44->addWidget(line_18);

        frame_132 = new QFrame(frame_130);
        frame_132->setObjectName(QString::fromUtf8("frame_132"));
        frame_132->setMinimumSize(QSize(61, 0));
        frame_132->setMaximumSize(QSize(80, 16777215));
        frame_132->setFrameShape(QFrame::StyledPanel);
        frame_132->setFrameShadow(QFrame::Raised);
        gridLayout_131 = new QGridLayout(frame_132);
        gridLayout_131->setSpacing(0);
        gridLayout_131->setObjectName(QString::fromUtf8("gridLayout_131"));
        gridLayout_131->setContentsMargins(0, 0, 0, 0);
        frame_134 = new QFrame(frame_132);
        frame_134->setObjectName(QString::fromUtf8("frame_134"));
        frame_134->setMaximumSize(QSize(16777215, 20));
        frame_134->setFrameShape(QFrame::StyledPanel);
        frame_134->setFrameShadow(QFrame::Raised);
        gridLayout_132 = new QGridLayout(frame_134);
        gridLayout_132->setSpacing(0);
        gridLayout_132->setObjectName(QString::fromUtf8("gridLayout_132"));
        gridLayout_132->setContentsMargins(0, 0, 0, 0);
        label_46 = new QLabel(frame_134);
        label_46->setObjectName(QString::fromUtf8("label_46"));
        label_46->setAlignment(Qt::AlignCenter);

        gridLayout_132->addWidget(label_46, 1, 0, 1, 1);


        gridLayout_131->addWidget(frame_134, 1, 0, 1, 1);

        frame_133 = new QFrame(frame_132);
        frame_133->setObjectName(QString::fromUtf8("frame_133"));
        frame_133->setFrameShape(QFrame::StyledPanel);
        frame_133->setFrameShadow(QFrame::Raised);
        gridLayout_133 = new QGridLayout(frame_133);
        gridLayout_133->setSpacing(0);
        gridLayout_133->setObjectName(QString::fromUtf8("gridLayout_133"));
        gridLayout_133->setContentsMargins(0, 0, 0, 0);
        widget_148 = new QWidget(frame_133);
        widget_148->setObjectName(QString::fromUtf8("widget_148"));
        widget_148->setMinimumSize(QSize(0, 0));
        widget_148->setMaximumSize(QSize(16777215, 16777215));
        gridLayout_130 = new QGridLayout(widget_148);
        gridLayout_130->setSpacing(0);
        gridLayout_130->setObjectName(QString::fromUtf8("gridLayout_130"));
        gridLayout_130->setContentsMargins(0, 0, 0, 0);
        planBtn = new QPushButton(widget_148);
        planBtn->setObjectName(QString::fromUtf8("planBtn"));
        planBtn->setCursor(QCursor(Qt::PointingHandCursor));
        planBtn->setStyleSheet(QString::fromUtf8("border:none;"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/icons/assets/Plan/blueprint.png"), QSize(), QIcon::Normal, QIcon::On);
        planBtn->setIcon(icon13);
        planBtn->setIconSize(QSize(30, 30));

        gridLayout_130->addWidget(planBtn, 0, 0, 1, 1);

        cmbPlan = new QComboBox(widget_148);
        cmbPlan->addItem(QString());
        cmbPlan->addItem(QString());
        cmbPlan->setObjectName(QString::fromUtf8("cmbPlan"));
        cmbPlan->setIconSize(QSize(16, 10));

        gridLayout_130->addWidget(cmbPlan, 1, 0, 1, 1);


        gridLayout_133->addWidget(widget_148, 0, 0, 1, 1);


        gridLayout_131->addWidget(frame_133, 0, 0, 1, 1);


        horizontalLayout_44->addWidget(frame_132);

        line_19 = new QFrame(frame_130);
        line_19->setObjectName(QString::fromUtf8("line_19"));
        line_19->setFrameShape(QFrame::VLine);
        line_19->setFrameShadow(QFrame::Sunken);

        horizontalLayout_44->addWidget(line_19);

        frame_4 = new QFrame(frame_130);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setMinimumSize(QSize(73, 0));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        gridLayout_13 = new QGridLayout(frame_4);
        gridLayout_13->setSpacing(0);
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        gridLayout_13->setContentsMargins(0, 0, 0, 0);
        widget_72 = new QWidget(frame_4);
        widget_72->setObjectName(QString::fromUtf8("widget_72"));
        gridLayout_18 = new QGridLayout(widget_72);
        gridLayout_18->setSpacing(0);
        gridLayout_18->setObjectName(QString::fromUtf8("gridLayout_18"));
        gridLayout_18->setContentsMargins(0, 0, 0, 0);
        widget_150 = new QWidget(widget_72);
        widget_150->setObjectName(QString::fromUtf8("widget_150"));
        verticalLayout_125 = new QVBoxLayout(widget_150);
        verticalLayout_125->setSpacing(0);
        verticalLayout_125->setObjectName(QString::fromUtf8("verticalLayout_125"));
        verticalLayout_125->setContentsMargins(0, 0, 0, 0);
        widget_152 = new QWidget(widget_150);
        widget_152->setObjectName(QString::fromUtf8("widget_152"));
        gridLayout_20 = new QGridLayout(widget_152);
        gridLayout_20->setSpacing(0);
        gridLayout_20->setObjectName(QString::fromUtf8("gridLayout_20"));
        gridLayout_20->setContentsMargins(0, 29, 0, 0);
        exportBtnPlan = new QPushButton(widget_152);
        exportBtnPlan->setObjectName(QString::fromUtf8("exportBtnPlan"));
        exportBtnPlan->setCursor(QCursor(Qt::PointingHandCursor));
        exportBtnPlan->setStyleSheet(QString::fromUtf8("border:none;"));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/icons/assets/output/export.png"), QSize(), QIcon::Normal, QIcon::On);
        exportBtnPlan->setIcon(icon14);
        exportBtnPlan->setIconSize(QSize(30, 30));

        gridLayout_20->addWidget(exportBtnPlan, 0, 0, 1, 1);


        verticalLayout_125->addWidget(widget_152);

        widget_153 = new QWidget(widget_150);
        widget_153->setObjectName(QString::fromUtf8("widget_153"));
        widget_153->setMaximumSize(QSize(16777215, 30));
        gridLayout_19 = new QGridLayout(widget_153);
        gridLayout_19->setSpacing(0);
        gridLayout_19->setObjectName(QString::fromUtf8("gridLayout_19"));
        gridLayout_19->setContentsMargins(0, 0, 0, 0);
        cmbExport = new QComboBox(widget_153);
        cmbExport->addItem(QString());
        cmbExport->addItem(QString());
        cmbExport->setObjectName(QString::fromUtf8("cmbExport"));
        cmbExport->setStyleSheet(QString::fromUtf8("border:none;"));

        gridLayout_19->addWidget(cmbExport, 0, 0, 1, 1);


        verticalLayout_125->addWidget(widget_153);

        label_44 = new QLabel(widget_150);
        label_44->setObjectName(QString::fromUtf8("label_44"));
        label_44->setMinimumSize(QSize(0, 20));
        label_44->setMaximumSize(QSize(16777215, 20));
        label_44->setAlignment(Qt::AlignCenter);

        verticalLayout_125->addWidget(label_44);


        gridLayout_18->addWidget(widget_150, 0, 0, 1, 1);


        gridLayout_13->addWidget(widget_72, 0, 0, 1, 1);


        horizontalLayout_44->addWidget(frame_4);

        line_16 = new QFrame(frame_130);
        line_16->setObjectName(QString::fromUtf8("line_16"));
        line_16->setFrameShape(QFrame::VLine);
        line_16->setFrameShadow(QFrame::Sunken);

        horizontalLayout_44->addWidget(line_16);

        frame_7 = new QFrame(frame_130);
        frame_7->setObjectName(QString::fromUtf8("frame_7"));
        frame_7->setMinimumSize(QSize(70, 0));
        frame_7->setFrameShape(QFrame::StyledPanel);
        frame_7->setFrameShadow(QFrame::Raised);
        gridLayout_58 = new QGridLayout(frame_7);
        gridLayout_58->setSpacing(0);
        gridLayout_58->setObjectName(QString::fromUtf8("gridLayout_58"));
        gridLayout_58->setContentsMargins(0, 0, 0, 0);
        widget_145 = new QWidget(frame_7);
        widget_145->setObjectName(QString::fromUtf8("widget_145"));
        gridLayout_59 = new QGridLayout(widget_145);
        gridLayout_59->setObjectName(QString::fromUtf8("gridLayout_59"));
        btnSymbol = new QPushButton(widget_145);
        btnSymbol->setObjectName(QString::fromUtf8("btnSymbol"));
        btnSymbol->setStyleSheet(QString::fromUtf8("border:none;"));
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/icons/assets/Plan/symbol.png"), QSize(), QIcon::Normal, QIcon::On);
        btnSymbol->setIcon(icon15);
        btnSymbol->setIconSize(QSize(30, 30));

        gridLayout_59->addWidget(btnSymbol, 0, 0, 1, 1);


        gridLayout_58->addWidget(widget_145, 0, 0, 1, 1);

        label_41 = new QLabel(frame_7);
        label_41->setObjectName(QString::fromUtf8("label_41"));
        label_41->setMinimumSize(QSize(0, 20));
        label_41->setMaximumSize(QSize(16777215, 20));
        label_41->setAlignment(Qt::AlignCenter);

        gridLayout_58->addWidget(label_41, 1, 0, 1, 1);


        horizontalLayout_44->addWidget(frame_7);

        line_20 = new QFrame(frame_130);
        line_20->setObjectName(QString::fromUtf8("line_20"));
        line_20->setFrameShape(QFrame::VLine);
        line_20->setFrameShadow(QFrame::Sunken);

        horizontalLayout_44->addWidget(line_20);

        frame_52 = new QFrame(frame_130);
        frame_52->setObjectName(QString::fromUtf8("frame_52"));
        frame_52->setMinimumSize(QSize(70, 0));
        frame_52->setFrameShape(QFrame::StyledPanel);
        frame_52->setFrameShadow(QFrame::Raised);
        gridLayout_122 = new QGridLayout(frame_52);
        gridLayout_122->setSpacing(0);
        gridLayout_122->setObjectName(QString::fromUtf8("gridLayout_122"));
        gridLayout_122->setContentsMargins(0, 0, 0, 0);
        widget_154 = new QWidget(frame_52);
        widget_154->setObjectName(QString::fromUtf8("widget_154"));
        gridLayout_125 = new QGridLayout(widget_154);
        gridLayout_125->setObjectName(QString::fromUtf8("gridLayout_125"));
        grabBtn_2 = new QPushButton(widget_154);
        grabBtn_2->setObjectName(QString::fromUtf8("grabBtn_2"));
        grabBtn_2->setStyleSheet(QString::fromUtf8("border:none;\n"
"QPushButton { background-color: gray; }\n"
"QPushButton:enabled { background-color: green; }"));
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/icons/assets/view/hand.png"), QSize(), QIcon::Normal, QIcon::On);
        grabBtn_2->setIcon(icon16);
        grabBtn_2->setIconSize(QSize(25, 25));

        gridLayout_125->addWidget(grabBtn_2, 0, 0, 1, 1);


        gridLayout_122->addWidget(widget_154, 0, 0, 1, 1);

        label_48 = new QLabel(frame_52);
        label_48->setObjectName(QString::fromUtf8("label_48"));
        label_48->setMinimumSize(QSize(0, 20));
        label_48->setMaximumSize(QSize(16777215, 20));
        label_48->setAlignment(Qt::AlignCenter);

        gridLayout_122->addWidget(label_48, 1, 0, 1, 1);


        horizontalLayout_44->addWidget(frame_52);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_44->addItem(horizontalSpacer_3);


        gridLayout_129->addWidget(frame_130, 0, 0, 1, 1);

        tabWidget->addTab(f_planning, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);


        horizontalLayout->addWidget(widget);


        gridLayout_2->addWidget(f_headerTabs, 1, 0, 1, 1);

        f_openGl = new QFrame(centralwidget);
        f_openGl->setObjectName(QString::fromUtf8("f_openGl"));
        f_openGl->setMinimumSize(QSize(0, 0));
        f_openGl->setFrameShape(QFrame::StyledPanel);
        f_openGl->setFrameShadow(QFrame::Raised);
        horizontalLayout_31 = new QHBoxLayout(f_openGl);
        horizontalLayout_31->setSpacing(0);
        horizontalLayout_31->setObjectName(QString::fromUtf8("horizontalLayout_31"));
        horizontalLayout_31->setContentsMargins(0, 0, 0, 0);
        widget_146 = new QWidget(f_openGl);
        widget_146->setObjectName(QString::fromUtf8("widget_146"));
        widget_146->setMinimumSize(QSize(200, 0));
        widget_146->setMaximumSize(QSize(200, 16777215));
        gridLayout_69 = new QGridLayout(widget_146);
        gridLayout_69->setObjectName(QString::fromUtf8("gridLayout_69"));
        tableWidget = new QTableWidget(widget_146);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_69->addWidget(tableWidget, 0, 0, 1, 1);


        horizontalLayout_31->addWidget(widget_146);

        widget_30 = new QWidget(f_openGl);
        widget_30->setObjectName(QString::fromUtf8("widget_30"));
        gridLayout_14 = new QGridLayout(widget_30);
        gridLayout_14->setSpacing(0);
        gridLayout_14->setObjectName(QString::fromUtf8("gridLayout_14"));
        gridLayout_14->setContentsMargins(0, 0, 0, 0);
        tabWidget_2 = new QTabWidget(widget_30);
        tabWidget_2->setObjectName(QString::fromUtf8("tabWidget_2"));
        tabWidget_2->setEnabled(true);
        tabWidget_2->setMinimumSize(QSize(0, 0));
        tabWidget_2->setMaximumSize(QSize(16777215, 16777215));
        tabWidget_2->setMouseTracking(false);
        tabWidget_2->setFocusPolicy(Qt::NoFocus);
        tabWidget_2->setAutoFillBackground(false);
        tabWidget_2->setTabPosition(QTabWidget::North);
        tabWidget_2->setTabShape(QTabWidget::Rounded);
        tabWidget_2->setIconSize(QSize(16, 16));
        tabWidget_2->setTabsClosable(false);
        tabWidget_2->setMovable(false);
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout_8 = new QGridLayout(tab_2);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        label_43 = new QLabel(tab_2);
        label_43->setObjectName(QString::fromUtf8("label_43"));
        label_43->setMaximumSize(QSize(300, 16777215));
        label_43->setPixmap(QPixmap(QString::fromUtf8(":/icons/assets/home/eulynx.jpg")));

        gridLayout_8->addWidget(label_43, 0, 0, 1, 1);

        tabWidget_2->addTab(tab_2, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        gridLayout_17 = new QGridLayout(tab_4);
        gridLayout_17->setSpacing(0);
        gridLayout_17->setObjectName(QString::fromUtf8("gridLayout_17"));
        gridLayout_17->setContentsMargins(0, 0, 0, 0);
        widget_151 = new QWidget(tab_4);
        widget_151->setObjectName(QString::fromUtf8("widget_151"));
        widget_151->setEnabled(true);
        widget_151->setMinimumSize(QSize(1700, 450));

        gridLayout_17->addWidget(widget_151, 0, 0, 1, 1);

        tabWidget_2->addTab(tab_4, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        verticalLayout_126 = new QVBoxLayout(tab_3);
        verticalLayout_126->setObjectName(QString::fromUtf8("verticalLayout_126"));
        widget_142 = new QGraphicsMainWindow(tab_3);
        widget_142->setObjectName(QString::fromUtf8("widget_142"));

        verticalLayout_126->addWidget(widget_142);

        tabWidget_2->addTab(tab_3, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tab->setFocusPolicy(Qt::NoFocus);
        tabWidget_2->addTab(tab, QString());

        gridLayout_14->addWidget(tabWidget_2, 0, 0, 1, 1);


        horizontalLayout_31->addWidget(widget_30);

        widget_147 = new QWidget(f_openGl);
        widget_147->setObjectName(QString::fromUtf8("widget_147"));
        widget_147->setMinimumSize(QSize(200, 0));
        widget_147->setMaximumSize(QSize(200, 16777215));
        gridLayout_70 = new QGridLayout(widget_147);
        gridLayout_70->setObjectName(QString::fromUtf8("gridLayout_70"));
        lblTrackName = new QLabel(widget_147);
        lblTrackName->setObjectName(QString::fromUtf8("lblTrackName"));

        gridLayout_70->addWidget(lblTrackName, 0, 0, 1, 1);

        tableWidget_2 = new QTableWidget(widget_147);
        if (tableWidget_2->columnCount() < 2)
            tableWidget_2->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(1, __qtablewidgetitem3);
        tableWidget_2->setObjectName(QString::fromUtf8("tableWidget_2"));
        tableWidget_2->setDragEnabled(true);
        tableWidget_2->setDragDropMode(QAbstractItemView::DragDrop);

        gridLayout_70->addWidget(tableWidget_2, 1, 0, 1, 1);


        horizontalLayout_31->addWidget(widget_147);


        gridLayout_2->addWidget(f_openGl, 2, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 2187, 25));
        menuNew = new QMenu(menubar);
        menuNew->setObjectName(QString::fromUtf8("menuNew"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuTools = new QMenu(menubar);
        menuTools->setObjectName(QString::fromUtf8("menuTools"));
        menuAccess_Data = new QMenu(menuTools);
        menuAccess_Data->setObjectName(QString::fromUtf8("menuAccess_Data"));
        menuView = new QMenu(menubar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        menuGrid_Style = new QMenu(menuView);
        menuGrid_Style->setObjectName(QString::fromUtf8("menuGrid_Style"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setEnabled(true);
        toolBar->setCursor(QCursor(Qt::PointingHandCursor));
        toolBar->setContextMenuPolicy(Qt::PreventContextMenu);
        toolBar->setOrientation(Qt::Horizontal);
        toolBar->setFloatable(true);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        viewToolBar = new QToolBar(MainWindow);
        viewToolBar->setObjectName(QString::fromUtf8("viewToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, viewToolBar);

        menubar->addAction(menuNew->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuView->menuAction());
        menubar->addAction(menuTools->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuNew->addAction(actionNew);
        menuNew->addAction(actionNew_2);
        menuNew->addAction(actionOpen);
        menuNew->addAction(actionImport);
        menuNew->addAction(actionSave);
        menuNew->addAction(actionSave_As);
        menuNew->addAction(actionPrint);
        menuNew->addAction(actionExit);
        menuEdit->addAction(actionUndo_2);
        menuEdit->addAction(actionRedo_2);
        menuEdit->addAction(actionDelete_Items);
        menuEdit->addAction(actionSelection_Mode);
        menuTools->addAction(menuAccess_Data->menuAction());
        menuTools->addAction(actionEULYNX_Validator);
        menuTools->addAction(actionText);
        menuAccess_Data->addAction(actionAdd_Data);
        menuAccess_Data->addAction(actionPreview_Data);
        menuAccess_Data->addAction(actionRemove_Data);
        menuView->addAction(actionXML_Json);
        menuView->addAction(actionPlanning_Tab);
        menuView->addAction(menuGrid_Style->menuAction());
        menuView->addAction(actionOSM);
        menuGrid_Style->addAction(actionDark_Theme);
        menuGrid_Style->addAction(actionLight_Rules);
        menuHelp->addAction(actionAbout_Qt);
        toolBar->addAction(actionNew_2);
        toolBar->addSeparator();
        toolBar->addAction(actionNew);
        toolBar->addAction(actionOpen);
        toolBar->addSeparator();
        toolBar->addAction(actionSave);
        toolBar->addSeparator();
        toolBar->addAction(actionSave_As);
        toolBar->addSeparator();
        toolBar->addAction(actionPrint);
        toolBar->addSeparator();
        toolBar->addSeparator();
        toolBar->addSeparator();
        viewToolBar->addAction(actionText);
        viewToolBar->addSeparator();

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "EULYNX", nullptr));
        actionNew->setText(QCoreApplication::translate("MainWindow", "New", nullptr));
#if QT_CONFIG(shortcut)
        actionNew->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
#if QT_CONFIG(shortcut)
        actionOpen->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
#if QT_CONFIG(shortcut)
        actionSave->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionNew_2->setText(QCoreApplication::translate("MainWindow", "New Project", nullptr));
        actionSave_As->setText(QCoreApplication::translate("MainWindow", "Save As", nullptr));
        actionPrint->setText(QCoreApplication::translate("MainWindow", "Print", nullptr));
        actionUndo->setText(QCoreApplication::translate("MainWindow", "Undo", nullptr));
        actionRedo->setText(QCoreApplication::translate("MainWindow", "Redo", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        actionAdd_symbol->setText(QCoreApplication::translate("MainWindow", "Add symbol", nullptr));
        actionAdd_symbol_options->setText(QCoreApplication::translate("MainWindow", "Add symbol options", nullptr));
        actionAdd_Data->setText(QCoreApplication::translate("MainWindow", "Add Data", nullptr));
        actionPreview_Data->setText(QCoreApplication::translate("MainWindow", "Preview Data", nullptr));
        actionRemove_Data->setText(QCoreApplication::translate("MainWindow", "Remove Data", nullptr));
        actionImport->setText(QCoreApplication::translate("MainWindow", "Import", nullptr));
        actionUndo_2->setText(QCoreApplication::translate("MainWindow", "Undo", nullptr));
#if QT_CONFIG(shortcut)
        actionUndo_2->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Z", nullptr));
#endif // QT_CONFIG(shortcut)
        actionRedo_2->setText(QCoreApplication::translate("MainWindow", "Redo", nullptr));
#if QT_CONFIG(shortcut)
        actionRedo_2->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Y", nullptr));
#endif // QT_CONFIG(shortcut)
        actionXML_Json->setText(QCoreApplication::translate("MainWindow", "XML_Json", nullptr));
        actionDelete_Items->setText(QCoreApplication::translate("MainWindow", "Delete Items", nullptr));
#if QT_CONFIG(tooltip)
        actionDelete_Items->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Delete all selected items<br/>Note: Track elements cannot be removed </p><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        actionSelection_Mode->setText(QCoreApplication::translate("MainWindow", "Selection Mode", nullptr));
        actionEULYNX_Validator->setText(QCoreApplication::translate("MainWindow", "EULYNX Validator", nullptr));
        actionPlanning_Tab->setText(QCoreApplication::translate("MainWindow", "Planning Tab", nullptr));
#if QT_CONFIG(shortcut)
        actionPlanning_Tab->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+P", nullptr));
#endif // QT_CONFIG(shortcut)
        actionText->setText(QCoreApplication::translate("MainWindow", "Text", nullptr));
#if QT_CONFIG(tooltip)
        actionText->setToolTip(QCoreApplication::translate("MainWindow", "Write Text", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionText->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+T", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAbout_Qt->setText(QCoreApplication::translate("MainWindow", "About Qt", nullptr));
        actionDark_Theme->setText(QCoreApplication::translate("MainWindow", "Dark Theme", nullptr));
        actionLight_Rules->setText(QCoreApplication::translate("MainWindow", "Light Rules", nullptr));
        actionOSM->setText(QCoreApplication::translate("MainWindow", "OSM", nullptr));
#if QT_CONFIG(tooltip)
        actionOSM->setToolTip(QCoreApplication::translate("MainWindow", "Visualize the track layout on Open Street Map", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        pushButton_77->setToolTip(QCoreApplication::translate("MainWindow", "Import files", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_77->setText(QString());
        label_47->setText(QCoreApplication::translate("MainWindow", "Modify Data", nullptr));
        label_46->setText(QCoreApplication::translate("MainWindow", "Plan", nullptr));
#if QT_CONFIG(tooltip)
        planBtn->setToolTip(QCoreApplication::translate("MainWindow", "Plan", nullptr));
#endif // QT_CONFIG(tooltip)
        planBtn->setText(QString());
        cmbPlan->setItemText(0, QCoreApplication::translate("MainWindow", "ECTS", nullptr));
        cmbPlan->setItemText(1, QCoreApplication::translate("MainWindow", "LST (CCS)", nullptr));

#if QT_CONFIG(tooltip)
        exportBtnPlan->setToolTip(QCoreApplication::translate("MainWindow", "Export to Eulynx", nullptr));
#endif // QT_CONFIG(tooltip)
        exportBtnPlan->setText(QString());
        cmbExport->setItemText(0, QCoreApplication::translate("MainWindow", "Eulynx", nullptr));
        cmbExport->setItemText(1, QCoreApplication::translate("MainWindow", "Plan Pro", nullptr));

        label_44->setText(QCoreApplication::translate("MainWindow", "Export", nullptr));
        btnSymbol->setText(QString());
        label_41->setText(QCoreApplication::translate("MainWindow", "Symbol", nullptr));
        grabBtn_2->setText(QString());
        label_48->setText(QCoreApplication::translate("MainWindow", "Grab", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(f_planning), QCoreApplication::translate("MainWindow", "Planning", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Object", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Properties", nullptr));
        label_43->setText(QString());
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Welcome", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_4), QCoreApplication::translate("MainWindow", "Start", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_3), QCoreApplication::translate("MainWindow", "QGraphics", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab), QString());
        lblTrackName->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_2->horizontalHeaderItem(0);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Object", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_2->horizontalHeaderItem(1);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Properties", nullptr));
        menuNew->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        menuTools->setTitle(QCoreApplication::translate("MainWindow", "Tools", nullptr));
        menuAccess_Data->setTitle(QCoreApplication::translate("MainWindow", "Access Data", nullptr));
        menuView->setTitle(QCoreApplication::translate("MainWindow", "View", nullptr));
        menuGrid_Style->setTitle(QCoreApplication::translate("MainWindow", "Grid Style", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
        viewToolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar_2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
