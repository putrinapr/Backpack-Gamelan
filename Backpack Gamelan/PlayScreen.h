#include <wx/wx.h>
#include <wx/sizer.h>
#include "Frame.h"

class PlayScreen : public wxPanel
{
	wxBitmap image;

public:
	PlayScreen(Frame* parent, wxString file, wxBitmapType format);
	~PlayScreen();

	void OnPauseButtonClick(wxCommandEvent& event);

	void paintEvent(wxPaintEvent & evt);
	void paintNow();

	void render(wxDC& dc);

private:
	Frame *parentFrame;
	DECLARE_EVENT_TABLE()
};