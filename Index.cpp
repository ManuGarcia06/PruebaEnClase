#include "stdafx.h"  //_____________________________________________ Index.cpp
#include "Index.h"

void Index::Window_Open(Web::HttpConnector& h)
{
}

void Index::btStaffSelect_onclick(Web::HttpConnector& h)
{
	h.NavigateTo(L"StaffSelect");
}

