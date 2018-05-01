#ifndef COPY_BUTTON_H
#define COPY_BUTTON_H
#include "../filesystem_management/gtk_filesystem_entry.h"
#include <gtkmm-3.0/gtkmm.h>
#include "action_button.h"
namespace actions{
	class CopyButton:public actions::ActionButton{
		
		public:
			CopyButton(Gtk::Entry &left_path, Gtk::Entry &right_path,FileSystemEntriesView &left,FileSystemEntriesView &right);
	};
}

#endif
