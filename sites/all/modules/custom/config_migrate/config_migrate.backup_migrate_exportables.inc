<?php
/**
 * @file
 * config_migrate.backup_migrate_exportables.inc
 */

/**
 * Implements hook_exportables_backup_migrate_destinations().
 */
function config_migrate_exportables_backup_migrate_destinations() {
  $export = array();

  $item = new stdClass();
  $item->disabled = FALSE; /* Edit this to true to make a default item disabled initially */
  $item->api_version = 1;
  $item->machine_name = 'backups';
  $item->name = 'backups';
  $item->subtype = 'file';
  $item->location = 'public://backups';
  $item->settings = array(
    'chmod' => '0777',
    'chgrp' => '',
  );
  $export['backups'] = $item;

  return $export;
}
