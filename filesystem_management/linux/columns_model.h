

class ModelColumns : public Gtk::TreeModelColumnRecord
{
public:
	Gtk::TreeModelColumn<Glib::ustring>entry_type;
	Gtk::TreeModelColumn<Glib::ustring>entry_name;
	Gtk::TreeModelColumn<Glib::ustring>permissions;
	Gtk::TreeModelColumn<gint>uid;
	Gtk::TreeModelColumn<gint>gid;
	Gtk::TreeModelColumn<gint>size;
	Gtk::TreeModelColumn<gint>nlinks;
	Gtk::TreeModelColumn<Glib::ustring>modification_date;
	ModelColumns();
};
