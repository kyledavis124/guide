#include "cMain.h"
#include "wx/splitter.h"

static const size_t NUMBER_OF_STATUS_BARS = 2;

cMain::cMain(const wxString& title)
    : wxFrame(nullptr, wxID_ANY, title)
{
    createMenuBar();
    CreateStatusBar(NUMBER_OF_STATUS_BARS);
}

cMain::~cMain() = default;

// Create the top menu bar.
void cMain::createMenuBar()
{
    auto* fileMenu = new wxMenu;
    auto* helpMenu = new wxMenu;

    helpMenu->Append(
        wxID_ABOUT,
        wxT("&About...\tF1"),
        wxT("Show about dialog."));

    fileMenu->Append(
        wxID_EXIT,
        wxT("E&xit\tAlt-X"),
        wxT("Quit the program."));

    auto* menuBar = new wxMenuBar();

    menuBar->Append(fileMenu, wxT("&File"));
    menuBar->Append(helpMenu, wxT("&Help"));

    SetMenuBar(menuBar);
}

void cMain::OnAbout(wxCommandEvent& event)
{
    wxString msg;

    msg.Printf(wxT("Welcome to %s."), GetTitle());
    wxMessageBox(msg, wxT("About Minimal"), wxOK | wxICON_INFORMATION, this);
}

void cMain::OnQuit(wxCommandEvent& event)
{
    Close();
}

// clang-format off

wxBEGIN_EVENT_TABLE(cMain, wxFrame)
	EVT_MENU(wxID_ABOUT, cMain::OnAbout)
	EVT_MENU(wxID_EXIT, cMain::OnQuit)
wxEND_EVENT_TABLE()
    // clang-format on
