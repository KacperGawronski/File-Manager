#ifndef MOVE_BUTTON_H
#define MOVE_BUTTON_H
#include "../filesystem_management/gtk_filesystem_entry.h"
#include <gtkmm-3.0/gtkmm.h>
#include "action_button.h"
namespace actions{
	class MoveButton:public actions::ActionButton{
		public:
			MoveButton(ACTION_BUTTON_CONSTRUCTOR_LONG_ARGS);
	};
}

#endif
