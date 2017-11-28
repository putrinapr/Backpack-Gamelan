#include "Menu.h"

BEGIN_EVENT_TABLE(Menu, wxPanel)
	EVT_PAINT(Menu::paintEvent)
	EVT_BUTTON(1002, Menu::OnPlayButtonClick)
	EVT_BUTTON(1003, Menu::OnFreeButtonClick)
	EVT_BUTTON(1004, Menu::OnHistoryButtonClick)
END_EVENT_TABLE()

Menu::Menu(Frame* parent, wxString file, wxBitmapType format) :
	wxPanel(parent, wxID_ANY), parentFrame(parent)
{
	image.LoadFile(file, format);
	wxButton* playButton = new wxButton(this, 1002, wxT("PLAY"), wxPoint(100, 225), wxDefaultSize);
	wxButton* freeButton = new wxButton(this, 1003, wxT("FREE"), wxPoint(360, 300), wxDefaultSize);
	wxButton* historyButton = new wxButton(this, 1004, wxT("HISTORY"), wxPoint(620, 390), wxDefaultSize);
}

Menu::~Menu()
{

}

void Menu::OnPlayButtonClick(wxCommandEvent & event)
{
	parentFrame->ShowPlay();
}

void Menu::OnFreeButtonClick(wxCommandEvent & event)
{
	parentFrame->ShowFree();
}

void Menu::OnHistoryButtonClick(wxCommandEvent & event)
{
	parentFrame->ShowHistory();
}

void Menu::paintEvent(wxPaintEvent & evt)
{
	wxPaintDC dc(this);
	render(dc);
}

void Menu::paintNow()
{
	wxClientDC dc(this);
	render(dc);
}

void Menu::render(wxDC&  dc)
{
	dc.DrawBitmap(image, 0, 0, false);
}