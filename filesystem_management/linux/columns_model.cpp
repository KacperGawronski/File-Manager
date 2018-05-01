#include "columns_model.h"

ModelColumns::ModelColumns(){
	add(entry_type);
	add(entry_name);
	add(permissions);
	add(nlinks);
	add(gid);
	add(uid);
	add(size);
	add(modification_date);
}
