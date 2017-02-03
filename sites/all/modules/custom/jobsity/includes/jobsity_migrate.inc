<?php


/**
 * Implements hook_form().
 */
function jobsity_form_records($form, &$form_state) {
  $form = array();

  $form['update_site'] = array(
    '#type' =>  'checkbox', 
    '#title' => t('Import content && Config'),
  );

  $form['submit'] = array(
      '#type' => 'submit',
      '#value' => 'Submit',
  );
  return $form;  
}

/*
 * Implements hook_validate().
 */

function jobsity_form_records_validate($form, &$form_state) {
  if ($form_state['values']['update_site'] == TRUE) {
     drupal_set_message("Working");
  }else{
    form_set_error('update_site', t('Please check for import config'));
  }
}


/*
 *Implements Hook Submit
 */
function jobsity_form_records_submit($form, &$form_state) {
    backup_migrate_include('profiles');
    $destination = "backups";
    $file_id = "jobsity-2017-02-02T12-08-20.mysql.gz";
    $settings = array(
        "from"  => "saved",
        "backup_migrate_restore_upload" => "",
        "file" => "backups/jobsity-2017-02-02T12-08-20.mysql.gz",
        "source_id" => "db",
        "filters" => array("utils_site_offline" => "0", "utils_site_offline_message" => "Jobsity is currently under maintenance. We should be back shortly. Thank you for your patience.", "use_cli" => "0"),
        "submit" => "Restore now",
        "form_build_id'" => "form-hK6SgrHCh3TsU5TLRd47xJlwo-5GI8vrUfuFcHPh6Z8",
        "form_token" => "r0OubNyiCXXEQqp-MH_uhUUVeB4hod4z3OLA8lbd-hc",
        "form_id" => "backup_migrate_ui_manual_restore_form();",
        "op" => "Restore now",
    );

    backup_migrate_perform_restore($destination, $file_id, $settings); 
} 