#include "Title.h"

BEGIN_EVENT_TABLE(Title, wxPanel)
	EVT_PAINT(Title::paintEvent)
	EVT_BUTTON(1001, Title::OnStartButtonClick)
END_EVENT_TABLE()

Title::Title(Frame* parent, wxString file, wxBitmapType format) :
	wxPanel(parent, wxID_ANY), parentFrame(parent)
{
	image.LoadFile(file, format);
	wxButton* startButton = new wxButton(this, 1001, wxT("Click to start!"), wxPoint(360, 570), wxDefaultSize);
}

Title::~Title()
{

}

void Title::OnStartButtonClick(wxCommandEvent & event)
{
	parentFrame->ShowMenu();
}

void Title::paintEvent(wxPaintEvent & evt)
{
	wxPaintDC dc(this);
	render(dc);
}

void Title::paintNow()
{
	wxClientDC dc(this);
	render(dc);
}

void Title::render(wxDC&  dc)
{
	dc.DrawBitmap(image, 0, 0, false);
}