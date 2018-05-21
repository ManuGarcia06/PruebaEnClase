#pragma once   //_____________________________________________ StaffSelect.h  
#include "resource.h"

class StaffSelect: public Web::Page
{
public:
	StaffSelect()
	{
	}
	~StaffSelect()
	{
	}
private:
	//______ Wintempla GUI manager section begin: DO NOT EDIT AFTER THIS LINE
	Web::Service serviceStaffSelect;
protected:
	void InitializeGui()
	{
		this->ID=L"StaffSelect";
		this->Title=L"StaffSelect";
		this->CssFile=L"cyan.css";
		this->JavascriptFile=L"StaffSelect.js";
		this->WebSiteIcon=L"WebSiteIcon.png";
		this->serviceStaffSelect.ID=L"serviceStaffSelect";
		this->serviceStaffSelect.Text=L"StaffSelect";
		this->AddChild(serviceStaffSelect);
	}
	//_________________________________________________
	void Window_Open(Web::HttpConnector& h);
	void EventHandler(Web::HttpConnector& h)
	{
	}
};
