<?php
/**
 * @file appui.page.inc
 *  Build control panel page.
 */

/**
 * Callback for path admin/appui.
 */
function appui_page($form, &$form_state) {
  ctools_include('export');
  $appcontrols = ctools_export_load_object('appui_appcontrol');

  $packages = appui_get_packages();

  // set up fieldsets
  foreach ($packages as $package) {
    if (!$package['disabled']) {
      $package_name = $package['package_name'];
      $package_title = $package['package_title'];
      $form[$package_name] = array(
        '#title' => t($package_title),
        '#type' => 'fieldset',
        '#collapsible' => TRUE,
        '#collapsed' => TRUE,
      );
      // fill fieldsets with appcontrols
      foreach ($package['appcontrols'] as $appcontrol) {
        $perm = (property_exists($appcontrol, 'permission') && $appcontrol->permission != NULL) ? $appcontrol->permission : "access features control panel";
        $appcontrol->disabled = (property_exists($appcontrol, 'disabled')) ? $appcontrol->disabled : FALSE;
        if (user_access($perm) && $appcontrol->disabled != TRUE) {
          $txt = t($appcontrol->title);
          $path = $appcontrol->path;
          $query = _appui_query($appcontrol);
          $link = ($query) ? l($txt, $path, array('query' => $query)) : l($txt, $path);
          $form[$package_name][$appcontrol->name] = array(
            '#type' => 'item',
            '#title' => $link,
            '#value' => t($appcontrol->description),
            '#weight' => (property_exists($appcontrol, 'weight')) ? $appcontrol->weight : 0,
            '#title_display' => 'invisible',
            '#theme' => 'appui_appcontrol',
          );
        }
      }
    }
  }
  // TODO Video
  // TODO Instructions
  return $form;
}

/**
 * Implementation of theme function for form elements.
 */
function theme_appui_appcontrol($variables) {
  $element = $variables['element'];
  $path = drupal_get_path('module', 'appui');
  drupal_add_css("$path/appui.css");

  $output = '';
  $output .= '<div class="appcontrol-title">' . $element['#title'] . '</div>';
  $output .= '<div class="appcontrol-description">' . $element['#value'] . '</div>';
  $output = '<div class="appcontrol">' . $output . '</div>';

  return $output;
}
