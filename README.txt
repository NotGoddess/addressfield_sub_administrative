Addressfield Sub-administrative Area
  by Sara Jacobson, drupal@notgoddess.com
-----------------------------------------

Description:
-----------------------------------------
This module allows the sub-administrative area as a field.
In the United States, the sub-administrative area corresponds
to a county within a state.

This information is stored with the other addressfield data.

Requirements:
-----------------------------------------
As this module is an add-on to addressfield, it requires the 
addressfield module. https://www.drupal.org/project/addressfield

Installation:
-----------------------------------------
Install in the usual manner:
- Unpack the module folder into your modules directiory
- Go to /admin/modules and enable.

Configuration:
-----------------------------------------
Under the Manage Fields area, add a Postal Address field, or
edit an existing one.

Select 'Show sub-administrative area (County);

The field will show as County before the administrative area (State).

The label can be changed using your preferred localization method.
For single language sites, add the string override as directed in 
settings.php or use the string override module.

Views
-----------------------------------------
The Addressfield module has built-in support for displaying the
sub-administrative area.
