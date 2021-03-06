#include "FreeScreen.h"

BEGIN_EVENT_TABLE(FreeScreen, wxPanel)
EVT_PAINT(FreeScreen::paintEvent)
EVT_BUTTON(3001, FreeScreen::OnPauseButtonClick)
END_EVENT_TABLE()

FreeScreen::FreeScreen(Frame* parent, wxString file, wxBitmapType format) :
	wxPanel(parent, wxID_ANY), parentFrame(parent)
{
	image.LoadFile(file, format);

	wxBitmap bitmap;
	bitmap.LoadFile("PauseButton.png", wxBITMAP_TYPE_PNG);

	wxBitmapButton* pauseButton = new wxBitmapButton(this, 3001, bitmap, wxPoint(10, 10), wxDefaultSize);
}

FreeScreen::~FreeScreen()
{

}

void FreeScreen::OnPauseButtonClick(wxCommandEvent & event)
{
	parentFrame->ShowFreePause();
}

void FreeScreen::paintEvent(wxPaintEvent & evt)
{
	wxPaintDC dc(this);
	render(dc);
}

void FreeScreen::paintNow()
{
	wxClientDC dc(this);
	render(dc);
}

void FreeScreen::render(wxDC&  dc)
{
	dc.DrawBitmap(image, 0, 0, false);
}