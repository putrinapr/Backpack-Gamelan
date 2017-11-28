#include "PauseFreeScreen.h"

BEGIN_EVENT_TABLE(PauseFreeScreen, wxPanel)
EVT_PAINT(PauseFreeScreen::paintEvent)
EVT_BUTTON(6001, PauseFreeScreen::OnBackButtonClick)
EVT_BUTTON(6002, PauseFreeScreen::OnMenuButtonClick)
END_EVENT_TABLE()

PauseFreeScreen::PauseFreeScreen(Frame* parent, wxString file, wxBitmapType format) :
	wxPanel(parent, wxID_ANY), parentFrame(parent)
{
	image.LoadFile(file, format);
	wxButton* backButton = new wxButton(this, 6001, wxT("BACK"), wxPoint(350, 250), wxDefaultSize);
	wxButton* menuButton = new wxButton(this, 6002, wxT("MAIN MENU"), wxPoint(350, 300), wxDefaultSize);
}

PauseFreeScreen::~PauseFreeScreen()
{

}

void PauseFreeScreen::OnBackButtonClick(wxCommandEvent & event)
{
	parentFrame->ShowFree();
}

void PauseFreeScreen::OnMenuButtonClick(wxCommandEvent & event)
{
	parentFrame->ShowMenu();
}

void PauseFreeScreen::paintEvent(wxPaintEvent & evt)
{
	wxPaintDC dc(this);
	render(dc);
}

void PauseFreeScreen::paintNow()
{
	wxClientDC dc(this);
	render(dc);
}

void PauseFreeScreen::render(wxDC&  dc)
{
	dc.DrawBitmap(image, 0, 0, false);
}