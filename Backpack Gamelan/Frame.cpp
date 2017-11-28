#include "wx/wx.h"
#include "Frame.h"
#include "Title.h"
#include "Menu.h"

Frame::Frame(const wxString& title)
	: wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(800, 640))
{
	this->InitComponents();
	SetIcon(wxICON(frame_icon));
	Centre();
}

void Frame::fitWindowSize()
{
	this->boxSizer->Fit(this);
	this->boxSizer->SetSizeHints(this);
	this->SetSize(wxSize(800, 640));
	this->Layout();
}

void Frame::InitComponents()
{
	boxSizer = new wxBoxSizer(wxVERTICAL);

	this->titleScreen = new Title(this, wxT("TitleScreen.png"), wxBITMAP_TYPE_PNG);
	this->titleScreen->Show(false);
	this->boxSizer->Add(titleScreen, 1, wxEXPAND, 0);

	this->menu = new Menu(this, wxT("Menu.png"), wxBITMAP_TYPE_PNG);
	this->menu->Show(false);
	this->boxSizer->Add(menu, 1, wxEXPAND, 0);

	SetSizer(boxSizer);

	ShowTitle();
}

void Frame::ShowTitle()
{
	this->titleScreen->Show(true);
	this->menu->Show(false);

	fitWindowSize();
}

void Frame::ShowMenu()
{
	this->titleScreen->Show(false);
	this->menu->Show(true);

	fitWindowSize();
}