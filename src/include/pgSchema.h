//////////////////////////////////////////////////////////////////////////
//
// pgAdmin III - PostgreSQL Tools
// Copyright (C) 2002, The pgAdmin Development Team
// This software is released under the pgAdmin Public Licence
//
// pgSchema.h PostgreSQL Schema
//
//////////////////////////////////////////////////////////////////////////

#ifndef PGSCHEMA_H
#define PGSCHEMA_H

// wxWindows headers
#include <wx/wx.h>

// App headers
#include "pgAdmin3.h"
#include "pgObject.h"
#include "pgServer.h"
#include "pgDatabase.h"

class pgCollection;

class pgSchema : public pgDatabaseObject
{
public:
    pgSchema(const wxString& newName = wxString(""));
    ~pgSchema();

    int GetIcon() { return PGICON_SCHEMA; }
    void ShowTreeDetail(wxTreeCtrl *browser, frmMain *form=0, wxListCtrl *properties=0, wxListCtrl *statistics=0, ctlSQLBox *sqlPane=0);
    static pgObject *ReadObjects(pgCollection *collection, wxTreeCtrl *browser, const wxString &restriction);
    static pgObject *ReadObjects(pgCollection *collection, wxTreeCtrl *browser);

    long GetSchemaTyp() const { return schemaTyp; }
    void iSetSchemaTyp(const long l) { schemaTyp=l; }
    bool GetSystemObject() const { return schemaTyp < 1; }

    bool CanDrop() { return true; }
    bool CanEdit() { return true; }
    bool CanCreate() { return true; }
    bool RequireDropConfirm() { return true; }

    bool DropObject(wxFrame *frame, wxTreeCtrl *browser);
    wxMenu *GetNewMenu();
    wxString GetSql(wxTreeCtrl *browser);
    pgObject *Refresh(wxTreeCtrl *browser, const wxTreeItemId item);

private:
    long schemaTyp; // 0: System 1: tempor�r 2: normal
};

#endif
