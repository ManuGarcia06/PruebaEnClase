#pragma once   //_____________________________________________ Index.h  
#include "resource.h"

class Index: public Web::Page
{
public:
	Index()
	{
	}
	~Index()
	{
	}
private:
	//______ Wintempla GUI manager section begin: DO NOT EDIT AFTER THIS LINE
	Web::Button btStaffSelect;
protected:
	void InitializeGui()
	{
		this->ID=L"Index";
		this->Title=L"Index";
		this->CssFile=L"cyan.css";
		this->JavascriptFile=L"Index.js";
		this->WebSiteIcon=L"WebSiteIcon.png";
		this->btStaffSelect.ID=L"btStaffSelect";
		this->btStaffSelect.Text=L"Staff List";
		this->AddChild(btStaffSelect);
	}
	//_________________________________________________
	void btStaffSelect_onclick(Web::HttpConnector& h);
	void Window_Open(Web::HttpConnector& h);
	void EventHandler(Web::HttpConnector& h)
	{
		if (btStaffSelect.IsEvent(h, LEX_HTML_ONCLICK)) {btStaffSelect_onclick(h);}
	}
};
