/*******************************************************************************

MihPhoto - Photo viewer for multi-touch devices
Copyright (C) 2010 Mihai Paslariu

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

*******************************************************************************/

#ifndef __CONFIG_H__
#define __CONFIG_H__

#include <QColor>
#include <QString>

#define CONFIG_FILE		".mihphoto.config"

struct Config
{
	// persistent
	QColor background_color;
	QColor text_color;
	bool multitouch;
	int drag_sensitivity;
	int flip_distance;
	double min_zoom;
	double max_zoom;
	bool show_file_name;
	int file_name_position;
	float file_name_size;
	bool rotate_by_exif;
	bool always_show_scroll;
	double zoom_speed;
	QString last_open_dir;
	QString start_dir;
	double thumb_size;
	double thumb_zoom_ratio;
	bool start_with_last_folder;
	bool start_with_custom_folder;
	bool show_folders;
	bool show_extra_buttons;
	bool thumbnails_crop;
	bool thumbnails_square;
	bool thumbnails_space;
	bool thumbnails_text_under_image;
	bool thumbnails_show_name;
	bool smooth_images;
	bool disable_animations;
	int choose_ui_size;

	// not persistent
	QString current_dir;
	QString install_dir;
	bool started_with_file;
	bool disable_settings_dialog;
	double thumb_zoom_min;
	double thumb_zoom_max;
	int ui_size; // computer at startup based on choose_ui_size
	
	int timer_duration;
	int image_scroll_speed;
	double folder_view_scroll_speed;
	double folder_scroll_inertia;
	double folder_scroll_average_speed_coef;
public:

	Config();

public:

	void loadDefaults( void );
	bool save( void );
	bool load( void );
	void computeUiSize( int screen_dpi );

private:

	QString _fromColor( QColor &c );
	QColor _toColor( QString &s );
	QString _fromBool( bool b );
	bool _toBool( QString &s );
	bool _dirExists( QString s );
};

#ifdef __CONFIGURATION_MAIN__
	Config g_config;
#else
	extern Config g_config;
#endif

#endif
