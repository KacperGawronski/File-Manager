#ifndef DELETE_BUTTON_H
#define DELETE_BUTTON_H
#include "../filesystem_management/gtk_filesystem_entry.h"
#include <gtkmm-3.0/gtkmm.h>
#include "action_button.h"
namespace actions{
	class DeleteButton:public actions::ActionButton{
		public:
			DeleteButton(ACTION_BUTTON_CONSTRUCTOR_LONG_ARGS);
	};
}

#endif
