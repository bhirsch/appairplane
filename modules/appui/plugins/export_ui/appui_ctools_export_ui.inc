<?php
/**
 * Define this Export UI plugin.
 */
$plugin = array(
  'schema' => 'appui_appcontrol', // As defined in hook_schema(), mymodule_myobj.
  'access' => 'administer appui', // Define a permission users must have to access these pages.
  // Define the menu item.
  'menu' => array(
    'menu prefix' => 'admin/structure',
    'menu item' => 'appui',
    'menu title' => 'Features Control Panel',
    'menu description' => 'Administer Features Control Panel Controls.',
  ),
  // Define user interface texts.
  'title singular' => t('control'),
  'title plural' => t('controls'),
  'title singular proper' => t('Features Control Panel Control'),
  'title plural proper' => t('Features Control Panel Controls'),
  // Define the names of the functions that provide the add/edit forms.
  'form' => array(
    'settings' => 'appui_ctools_export_ui_form',
    // 'submit' and 'validate' are also valid callbacks.
  ),
  // Use this to modify the default export UI interface.
  'handler' => array(
    'class' => 'appui_export_ui',
    'parent' => 'ctools_export_ui',
  ),
);

/**
 * Define the preset add/edit form.
 */
function appui_ctools_export_ui_form(&$form, &$form_state) {
  $appcontrol = $form_state['item'];

  // appui's configuration interface.
  /* Apparently Ctools includes this field automatically on its own.
   $form['name'] = array(
   '#type' => 'textfield',
   '#title' => t('Machine Name'),
   '#description' => t('lowercase, no spaces or punctuation'),
   '#default_value' => $appcontrol->name,
   '#required' => true,
   );
   // */
  $form['title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#description' => t('Human readable control name.'),
    '#default_value' => $appcontrol->title,
    '#required' => true,
  );
  $form['package'] = array(
    '#type' => 'textfield',
    '#title' => t('Feature Set (Package)'),
    '#description' => t('Determine which feature set the control will '
                       . 'be included in.'),
    '#default_value' => $appcontrol->package,
    '#required' => true,
  );
  $form['description'] = array(
    '#type' => 'textfield',
    '#title' => t('Description'),
    '#description' => t('Describe what this control does.'),
    '#default_value' => $appcontrol->description,
    '#required' => true,
  );
  $form['path'] = array(
    '#type' => 'textfield',
    '#title' => t('Path'),
    '#description' => t('Send users to this path, e.g. admin/example'),
    '#default_value' => $appcontrol->path,
    '#required' => true,
  );
  $form['query'] = array(
    '#type' => 'textfield',
    '#title' => t('Query'),
    '#description' => t('Include this query string in the URL, e.g. x=y&a=b '
                       . 'will be added to the URL like this: '
                       . 'http://example.com/admin/example?x=y&a=b'),
    '#default_value' => $appcontrol->query,
    '#required' => false,
  );
  /*  // TODO Figure out how to display this stuff on admin/appui page
   $form['video_title'] = array(
   '#type' => 'textfield',
   '#title' => t('Instructional Video Title'),
   '#description' => t('Title of instructional video'),
   '#default_value' => $appcontrol->video_title,
   '#required' => false,
   );
   $form['video'] = array(
   '#type' => 'textarea',
   '#title' => t('Video'),
   '#description' => t('e.g. <embed>HTML for YouTube, Vimeo, etc., video goes here</embed>'),
   '#default_value' => $appcontrol->video,
   '#required' => false,
   );
   $form['instructions_title'] = array(
   '#type' => 'textfield',
   '#title' => t('Instructions Title'),
   '#description' => t('Written instructions'),
   '#default_value' => $appcontrol->video_title,
   '#required' => false,
   );
   $form['instructions'] = array(
   '#type' => 'textarea',
   '#title' => t('Instructions'),
   '#description' => t('Include written instructions for the end-user here'),
   '#default_value' => $appcontrol->video,
   '#required' => false,
   );
   // */
  $form['permission'] = array(
    '#type' => 'textfield',
    '#title' => t('Required Permission'),
    '#description' => t(''),
    '#default_value' => $appcontrol->permission,
    '#required' => false,
  );
  $form['weight'] = array(
    '#type' => 'textfield',
    '#title' => t('Weight'),
    '#description' => t('Sort order of controls'),
    '#default_value' => $appcontrol->weight,
    '#required' => false,
  );

}
