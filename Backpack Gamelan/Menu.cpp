#include "Menu.h"

BEGIN_EVENT_TABLE(Menu, wxPanel)
	EVT_PAINT(Menu::paintEvent)
END_EVENT_TABLE()

Menu::Menu(Frame* parent, wxString file, wxBitmapType format) :
	wxPanel(parent, wxID_ANY), parentFrame(parent)
{
	image.LoadFile(file, format);
}

Menu::~Menu()
{

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