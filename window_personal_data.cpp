#include "window_personal_data.h"
#include "style.h"

WindowPersonalData::WindowPersonalData() {

    p_personalData = new Ui_PersonalData;
    p_personalData->setupUi(this);

    style();
    toolTipWidget();
    connectSlots();
}

WindowPersonalData::~WindowPersonalData() {

    delete p_personalData;
}

void WindowPersonalData::style() {

    this->setStyleSheet("background:#626262;");

    this->p_personalData->l_ID->          setStyleSheet("color: white;");
    this->p_personalData->l_branch->      setStyleSheet("color: white;");
    this->p_personalData->l_job_title->   setStyleSheet("color: white;");
    this->p_personalData->l_name->        setStyleSheet("color: white;");
    this->p_personalData->l_task->        setStyleSheet("color: white;");
    this->p_personalData->l_name_company->setStyleSheet("color: white;");
    this->p_personalData->l_1->           setStyleSheet("color: white;");
    this->p_personalData->l_2->           setStyleSheet("color: white;");
    this->p_personalData->l_3->           setStyleSheet("color: white;");
    this->p_personalData->l_4->           setStyleSheet("color: white;");
    this->p_personalData->l_5->           setStyleSheet("color: white;");
    this->p_personalData->l_6->           setStyleSheet("color: white;");
}

void WindowPersonalData::toolTipWidget() {


}

void WindowPersonalData::connectSlots() {


}
