#include "stdafx.h"  //_____________________________________________ StaffSelect.cpp
#include "StaffSelect.h"

//#include "StaffSelect.h" //<< ADD THIS LINE IN THE StaffList.cpp FILE

// http://localhost/StaffList.dll?windowID=StaffSelect
void StaffSelect::Window_Open(Web::HttpConnector& h)
{
	serviceStaffSelect.soapEnvelope.ActionXmlns = L"http://www.ugto.mx/StaffList";
	//_____________________________________________ Prepare a sample XML node, so that ExcecuteSelect create the rest of the nodes like this
	list<Sys::Xml>::iterator response;
	if (serviceStaffSelect.soapEnvelope.GetResponse(response) == false)return;
	Sys::Xml& staff = response->AddChild(L"staff");
	staff.AddChild(L"staff_id");
	staff.AddChild(L"last_name");
	staff.AddChild(L"first_name");
	staff.AddChild(L"position");
	staff.AddChild(L"salary");

	Sql::SqlConnection conn;
	try
	{
		//conn.OpenSession(DSN, USERNAME, PASSWORD); //Control Panel>Administrative Tools>Data Sources (ODBC)>Create dsn_myDatabase
		conn.OpenSession(NULL, CONNECTION_STRING);
		conn.ExecuteSelect(L"SELECT staff_id, last_name, first_name, position, salary FROM staff", 100, serviceStaffSelect.soapEnvelope);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}
}
