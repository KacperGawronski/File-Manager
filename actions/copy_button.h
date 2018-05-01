#ifndef COPY_BUTTON_H
#define COPY_BUTTON_H
#include "../filesystem_management/gtk_filesystem_entry.h"
#include <gtkmm-3.0/gtkmm.h>
#include "action_button.h"
namespace actions{
	class CopyButton:public actions::ActionButton{
		
		public:
			CopyButton(ACTION_BUTTON_CONSTRUCTOR_LONG_ARGS);
	};
}

#endif
