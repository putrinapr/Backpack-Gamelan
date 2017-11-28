#include "PausePlayScreen.h"

BEGIN_EVENT_TABLE(PausePlayScreen, wxPanel)
EVT_PAINT(PausePlayScreen::paintEvent)
EVT_BUTTON(5001, PausePlayScreen::OnBackButtonClick)
EVT_BUTTON(5002, PausePlayScreen::OnMenuButtonClick)
END_EVENT_TABLE()

PausePlayScreen::PausePlayScreen(Frame* parent, wxString file, wxBitmapType format) :
	wxPanel(parent, wxID_ANY), parentFrame(parent)
{
	image.LoadFile(file, format);
	wxButton* backButton = new wxButton(this, 5001, wxT("BACK"), wxPoint(350, 250), wxDefaultSize);
	wxButton* menuButton = new wxButton(this, 5002, wxT("MAIN MENU"), wxPoint(350, 300), wxDefaultSize);
}

PausePlayScreen::~PausePlayScreen()
{

}

void PausePlayScreen::OnBackButtonClick(wxCommandEvent & event)
{
	parentFrame->ShowPlay();
}

void PausePlayScreen::OnMenuButtonClick(wxCommandEvent & event)
{
	parentFrame->ShowMenu();
}

void PausePlayScreen::paintEvent(wxPaintEvent & evt)
{
	wxPaintDC dc(this);
	render(dc);
}

void PausePlayScreen::paintNow()
{
	wxClientDC dc(this);
	render(dc);
}

void PausePlayScreen::render(wxDC&  dc)
{
	dc.DrawBitmap(image, 0, 0, false);
}