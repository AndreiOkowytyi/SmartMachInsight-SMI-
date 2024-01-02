#include "working_window.h"
#include "style.h"

WorkingWindow::WorkingWindow() {

    this->p_workingWindow = new Ui_WorkingWindow;
    this->p_workingWindow->setupUi(this);

    style();
    connectSlots();
    toolTipWidget();
}

WorkingWindow::~WorkingWindow() {

    if(this->p_workingWindow      != nullptr) delete this->p_workingWindow;
    if(this->p_windowPersonalData != nullptr) delete this->p_windowPersonalData;
}

void WorkingWindow::style() {

    this->setStyleSheet("background: white");

    // Стиль для QLineEdit
    this->p_workingWindow->l_e_find_product->setStyleSheet(StyleWorkingWindow::search());

    // Стиль для QWidget
    this->p_workingWindow->w_main_panel->setStyleSheet(StyleWorkingWindow::widgetSearch());
    this->p_workingWindow->w_left_panel->setStyleSheet(StyleWorkingWindow::widgetSearch());
    this->p_workingWindow->w_storage->   setStyleSheet(StyleWorkingWindow::storage());

    // Стиль для QToolButton
    this->p_workingWindow->t_b_find->         setStyleSheet(StyleWorkingWindow::find());
    this->p_workingWindow->t_b_back->         setStyleSheet(StyleWorkingWindow::back());
    this->p_workingWindow->t_b_exit->         setStyleSheet(StyleWorkingWindow::exit());
    this->p_workingWindow->t_b_plus_position->setStyleSheet(StyleWorkingWindow::plusPosition());
    this->p_workingWindow->t_b_personal_data->setStyleSheet(StyleWorkingWindow::personalData());
    this->p_workingWindow->t_b_update->       setStyleSheet(StyleWorkingWindow::update());
    this->p_workingWindow->t_b_massage->      setStyleSheet(StyleWorkingWindow::message());

    // Стиль для QPushButton
    this->p_workingWindow->p_b_company->        setStyleSheet(StyleWorkingWindow::buttonControlPanel());
    this->p_workingWindow->p_b_tasks->          setStyleSheet(StyleWorkingWindow::buttonControlPanel());
    this->p_workingWindow->p_b_filter->         setStyleSheet(StyleWorkingWindow::buttonControlPanel());
    this->p_workingWindow->p_b_setting->        setStyleSheet(StyleWorkingWindow::buttonControlPanel());
    this->p_workingWindow->p_b_create_tasks->   setStyleSheet(StyleWorkingWindow::buttonControlPanel());
    this->p_workingWindow->p_b_material->       setStyleSheet(StyleWorkingWindow::buttonControlPanel());
    this->p_workingWindow->p_b_storage->        setStyleSheet(StyleWorkingWindow::buttonControlPanel());
    this->p_workingWindow->p_b_personal->       setStyleSheet(StyleWorkingWindow::buttonControlPanel());
    this->p_workingWindow->p_b_accounting->     setStyleSheet(StyleWorkingWindow::buttonControlPanel());
    this->p_workingWindow->p_b_report->         setStyleSheet(StyleWorkingWindow::buttonControlPanel());
    this->p_workingWindow->p_b_buy_items->      setStyleSheet(StyleWorkingWindow::buttonControlPanel());
    this->p_workingWindow->p_b_column_name->    setStyleSheet(StyleWorkingWindow::column());
    this->p_workingWindow->p_b_column_material->setStyleSheet(StyleWorkingWindow::column());
    this->p_workingWindow->p_b_column_count->   setStyleSheet(StyleWorkingWindow::column());
    this->p_workingWindow->p_b_column_measures->setStyleSheet(StyleWorkingWindow::column());

    // Стиль для QScrollArea
    this->p_workingWindow->scrollArea->setStyleSheet(StyleWorkingWindow::scrollArea());

    // Стиль для QLabel
    this->p_workingWindow->l_personal->      setStyleSheet(StyleWorkingWindow::lable());
    this->p_workingWindow->l_exit->          setStyleSheet(StyleWorkingWindow::lable());
    this->p_workingWindow->l_product_picture->setPixmap(QPixmap(":/background/no_image_.jpg"));
    this->p_workingWindow->l_product_picture->setScaledContents(true);

    //////////////
    fillingData();
}

void WorkingWindow::toolTipWidget() {

    // ToolTip QToolButton
    this->p_workingWindow->t_b_personal_data->setToolTip("Персональні данні користувача");
    this->p_workingWindow->t_b_massage->      setToolTip("Чат/повідослення");
    this->p_workingWindow->t_b_exit->         setToolTip("Вихід із аккаунту");
    this->p_workingWindow->t_b_find->         setToolTip("Пошук");
    this->p_workingWindow->t_b_update->       setToolTip("Оновити данні відносно запиту");
    this->p_workingWindow->t_b_plus_position->setToolTip("Додати нову номенклатурну позицію");
    this->p_workingWindow->t_b_back->         setToolTip("Повернутися назад");

    // ToolTip QPushButton
    this->p_workingWindow->p_b_column_count->   setToolTip("Сортування по кількості");
    this->p_workingWindow->p_b_column_material->setToolTip("Сортування по матеріалу");
    this->p_workingWindow->p_b_column_name->    setToolTip("Сортування по назві");
}


void WorkingWindow::connectSlots() {

    QObject::connect(this->p_workingWindow->t_b_personal_data, &QToolButton::clicked, this, [this](){

        if(this->p_windowPersonalData == nullptr) {

            this->p_windowPersonalData = new WindowPersonalData;
            this->p_windowPersonalData->show();

        } else this->p_windowPersonalData->show();
    });
}

void WorkingWindow::fillingData() {

    /////////////////////////////////////////////////////////////////////////////////////////

    int b = 0;
    bool flag = false;
    int xa = this->p_workingWindow->scrollAreaWidgetContents->height() / 25;

    for(int x = 0; x < 200; x++) {

        if(x > xa || x == xa) {

            this->p_workingWindow->scrollAreaWidgetContents->setFixedHeight(p_workingWindow->scrollAreaWidgetContents->height() + 25);
        }

        QPushButton *pButton_1 = new QPushButton(QString::number(x), this->p_workingWindow->scrollAreaWidgetContents);
        pButton_1->setGeometry(this->p_workingWindow->p_b_column_name->x(), b, this->p_workingWindow->p_b_column_name->width(), 25);

        QPushButton *pButton_2 = new QPushButton(QString::number(x), this->p_workingWindow->scrollAreaWidgetContents);
        pButton_2->setGeometry(this->p_workingWindow->p_b_column_material->x(), b, this->p_workingWindow->p_b_column_material->width(), 25);

        QPushButton *pButton_3 = new QPushButton(QString::number(x), this->p_workingWindow->scrollAreaWidgetContents);
        pButton_3->setGeometry(this->p_workingWindow->p_b_column_count->x(), b, this->p_workingWindow->p_b_column_count->width(), 25);

        QPushButton *pButton_4 = new QPushButton(QString::number(x), this->p_workingWindow->scrollAreaWidgetContents);
        pButton_4->setGeometry(this->p_workingWindow->p_b_column_measures->x(), b, this->p_workingWindow->p_b_column_measures->width(), 25);
        b+=25;

        if(flag) {

            pButton_1->setStyleSheet(StyleWorkingWindow::oneLineTable());
            pButton_2->setStyleSheet(StyleWorkingWindow::oneLineTable());
            pButton_3->setStyleSheet(StyleWorkingWindow::oneLineTable());
            pButton_4->setStyleSheet(StyleWorkingWindow::oneLineTable());
            flag = false;

        } else {

            pButton_1->setStyleSheet(StyleWorkingWindow::secondLineTable());
            pButton_2->setStyleSheet(StyleWorkingWindow::secondLineTable());
            pButton_3->setStyleSheet(StyleWorkingWindow::secondLineTable());
            pButton_4->setStyleSheet(StyleWorkingWindow::secondLineTable());
            flag = true;
        }
    }
}
