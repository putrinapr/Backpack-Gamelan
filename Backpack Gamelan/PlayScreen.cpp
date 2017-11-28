#include "PlayScreen.h"

BEGIN_EVENT_TABLE(PlayScreen, wxPanel)
EVT_PAINT(PlayScreen::paintEvent)
EVT_BUTTON(2001, PlayScreen::OnPauseButtonClick)
END_EVENT_TABLE()

PlayScreen::PlayScreen(Frame* parent, wxString file, wxBitmapType format) :
	wxPanel(parent, wxID_ANY), parentFrame(parent)
{
	image.LoadFile(file, format);
	wxButton* pauseButton = new wxButton(this, 2001, wxT("PAUSE"), wxPoint(10, 10), wxDefaultSize);
}

PlayScreen::~PlayScreen()
{

}

void PlayScreen::OnPauseButtonClick(wxCommandEvent & event)
{
	parentFrame->ShowPlayPause();
}

void PlayScreen::paintEvent(wxPaintEvent & evt)
{
	wxPaintDC dc(this);
	render(dc);
}

void PlayScreen::paintNow()
{
	wxClientDC dc(this);
	render(dc);
}

void PlayScreen::render(wxDC&  dc)
{
	dc.DrawBitmap(image, 0, 0, false);
}