<?php


/**
 * Implements hook_views_default_views().
 */
function rooms_booking_views_views_default_views() {
  $views = array();

  $view = new view();
  $view->name = 'upcoming_bookings';
  $view->description = 'A list of all bookings';
  $view->tag = 'rooms';
  $view->base_table = 'rooms_bookings';
  $view->human_name = 'Upcoming Bookings';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Upcoming Bookings';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer rooms_booking entities';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'booking_id' => 'booking_id',
    'operations' => 'operations',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'booking_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'operations' => array(
      'align' => '',
      'separator' => '',
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'Empty Message';
  $handler->display->display_options['empty']['area']['content'] = 'No bookings have been created yet.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: Bookings: Owner */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'rooms_bookings';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  /* Field: Bookings: Bookings ID */
  $handler->display->display_options['fields']['booking_id']['id'] = 'booking_id';
  $handler->display->display_options['fields']['booking_id']['table'] = 'rooms_bookings';
  $handler->display->display_options['fields']['booking_id']['field'] = 'booking_id';
  $handler->display->display_options['fields']['booking_id']['label'] = 'Booking';
  /* Field: Bookings: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'rooms_bookings';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Customer';
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = FALSE;
  /* Field: Bookings: Start Date */
  $handler->display->display_options['fields']['start_date']['id'] = 'start_date';
  $handler->display->display_options['fields']['start_date']['table'] = 'rooms_bookings';
  $handler->display->display_options['fields']['start_date']['field'] = 'start_date';
  $handler->display->display_options['fields']['start_date']['label'] = 'Arrival';
  $handler->display->display_options['fields']['start_date']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['start_date']['date_format'] = 'custom';
  $handler->display->display_options['fields']['start_date']['custom_date_format'] = 'd-m-Y';
  /* Field: Bookings: End Date */
  $handler->display->display_options['fields']['end_date']['id'] = 'end_date';
  $handler->display->display_options['fields']['end_date']['table'] = 'rooms_bookings';
  $handler->display->display_options['fields']['end_date']['field'] = 'end_date';
  $handler->display->display_options['fields']['end_date']['label'] = 'Departure';
  $handler->display->display_options['fields']['end_date']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['end_date']['date_format'] = 'custom';
  $handler->display->display_options['fields']['end_date']['custom_date_format'] = 'd-m-Y';
  /* Field: Bookings: Unit */
  $handler->display->display_options['fields']['unit_id']['id'] = 'unit_id';
  $handler->display->display_options['fields']['unit_id']['table'] = 'rooms_bookings';
  $handler->display->display_options['fields']['unit_id']['field'] = 'unit_id';
  $handler->display->display_options['fields']['unit_id']['hide_alter_empty'] = FALSE;
  /* Field: Bookings: Booking Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'rooms_bookings';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = 'Type';
  $handler->display->display_options['fields']['type']['hide_alter_empty'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name_1']['id'] = 'name_1';
  $handler->display->display_options['fields']['name_1']['table'] = 'users';
  $handler->display->display_options['fields']['name_1']['field'] = 'name';
  $handler->display->display_options['fields']['name_1']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name_1']['label'] = 'Owner';
  /* Field: Bookings: Order_id */
  $handler->display->display_options['fields']['order_id']['id'] = 'order_id';
  $handler->display->display_options['fields']['order_id']['table'] = 'rooms_bookings';
  $handler->display->display_options['fields']['order_id']['field'] = 'order_id';
  $handler->display->display_options['fields']['order_id']['label'] = 'Order';
  $handler->display->display_options['fields']['order_id']['hide_alter_empty'] = FALSE;
  /* Field: Bookings: Operations links */
  $handler->display->display_options['fields']['operations']['id'] = 'operations';
  $handler->display->display_options['fields']['operations']['table'] = 'rooms_bookings';
  $handler->display->display_options['fields']['operations']['field'] = 'operations';
  $handler->display->display_options['fields']['operations']['hide_alter_empty'] = FALSE;
  /* Sort criterion: Bookings: Bookings ID */
  $handler->display->display_options['sorts']['booking_id']['id'] = 'booking_id';
  $handler->display->display_options['sorts']['booking_id']['table'] = 'rooms_bookings';
  $handler->display->display_options['sorts']['booking_id']['field'] = 'booking_id';
  $handler->display->display_options['sorts']['booking_id']['order'] = 'DESC';
  /* Filter criterion: Bookings: Start Date */
  $handler->display->display_options['filters']['start_date']['id'] = 'start_date';
  $handler->display->display_options['filters']['start_date']['table'] = 'rooms_bookings';
  $handler->display->display_options['filters']['start_date']['field'] = 'start_date';
  $handler->display->display_options['filters']['start_date']['operator'] = 'between';
  $handler->display->display_options['filters']['start_date']['value']['min'] = 'now';
  $handler->display->display_options['filters']['start_date']['value']['max'] = '+7 days';
  $handler->display->display_options['filters']['start_date']['value']['type'] = 'offset';
  $handler->display->display_options['filters']['start_date']['exposed'] = TRUE;
  $handler->display->display_options['filters']['start_date']['expose']['operator_id'] = 'start_date_op';
  $handler->display->display_options['filters']['start_date']['expose']['label'] = 'Start Date';
  $handler->display->display_options['filters']['start_date']['expose']['operator'] = 'start_date_op';
  $handler->display->display_options['filters']['start_date']['expose']['identifier'] = 'start_date';
  /* Filter criterion: Bookings: Booking_status */
  $handler->display->display_options['filters']['booking_status']['id'] = 'booking_status';
  $handler->display->display_options['filters']['booking_status']['table'] = 'rooms_bookings';
  $handler->display->display_options['filters']['booking_status']['field'] = 'booking_status';
  $handler->display->display_options['filters']['booking_status']['value'] = array(
    0 => '0',
    1 => '1',
  );

  /* Display: Upcoming Bookings */
  $handler = $view->new_display('block', 'Upcoming Bookings', 'block_1');

  $views['upcoming_bookings'] = $view;


  $view = new view();
  $view->name = 'outgoing_bookings';
  $view->description = 'A list of all bookings';
  $view->tag = 'rooms';
  $view->base_table = 'rooms_bookings';
  $view->human_name = 'Outgoing Bookings';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Outgoing Bookings';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer rooms_booking entities';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'booking_id' => 'booking_id',
    'operations' => 'operations',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'booking_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'operations' => array(
      'align' => '',
      'separator' => '',
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'Empty Message';
  $handler->display->display_options['empty']['area']['content'] = 'No bookings have been created yet.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: Bookings: Owner */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'rooms_bookings';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  /* Field: Bookings: Bookings ID */
  $handler->display->display_options['fields']['booking_id']['id'] = 'booking_id';
  $handler->display->display_options['fields']['booking_id']['table'] = 'rooms_bookings';
  $handler->display->display_options['fields']['booking_id']['field'] = 'booking_id';
  $handler->display->display_options['fields']['booking_id']['label'] = 'Booking';
  /* Field: Bookings: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'rooms_bookings';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Customer';
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = FALSE;
  /* Field: Bookings: Start Date */
  $handler->display->display_options['fields']['start_date']['id'] = 'start_date';
  $handler->display->display_options['fields']['start_date']['table'] = 'rooms_bookings';
  $handler->display->display_options['fields']['start_date']['field'] = 'start_date';
  $handler->display->display_options['fields']['start_date']['label'] = 'Arrival';
  $handler->display->display_options['fields']['start_date']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['start_date']['date_format'] = 'custom';
  $handler->display->display_options['fields']['start_date']['custom_date_format'] = 'd-m-Y';
  /* Field: Bookings: End Date */
  $handler->display->display_options['fields']['end_date']['id'] = 'end_date';
  $handler->display->display_options['fields']['end_date']['table'] = 'rooms_bookings';
  $handler->display->display_options['fields']['end_date']['field'] = 'end_date';
  $handler->display->display_options['fields']['end_date']['label'] = 'Departure';
  $handler->display->display_options['fields']['end_date']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['end_date']['date_format'] = 'custom';
  $handler->display->display_options['fields']['end_date']['custom_date_format'] = 'd-m-Y';
  /* Field: Bookings: Unit */
  $handler->display->display_options['fields']['unit_id']['id'] = 'unit_id';
  $handler->display->display_options['fields']['unit_id']['table'] = 'rooms_bookings';
  $handler->display->display_options['fields']['unit_id']['field'] = 'unit_id';
  $handler->display->display_options['fields']['unit_id']['hide_alter_empty'] = FALSE;
  /* Field: Bookings: Booking Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'rooms_bookings';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = 'Type';
  $handler->display->display_options['fields']['type']['hide_alter_empty'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name_1']['id'] = 'name_1';
  $handler->display->display_options['fields']['name_1']['table'] = 'users';
  $handler->display->display_options['fields']['name_1']['field'] = 'name';
  $handler->display->display_options['fields']['name_1']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name_1']['label'] = 'Owner';
  /* Field: Bookings: Order_id */
  $handler->display->display_options['fields']['order_id']['id'] = 'order_id';
  $handler->display->display_options['fields']['order_id']['table'] = 'rooms_bookings';
  $handler->display->display_options['fields']['order_id']['field'] = 'order_id';
  $handler->display->display_options['fields']['order_id']['label'] = 'Order';
  $handler->display->display_options['fields']['order_id']['hide_alter_empty'] = FALSE;
  /* Field: Bookings: Operations links */
  $handler->display->display_options['fields']['operations']['id'] = 'operations';
  $handler->display->display_options['fields']['operations']['table'] = 'rooms_bookings';
  $handler->display->display_options['fields']['operations']['field'] = 'operations';
  $handler->display->display_options['fields']['operations']['hide_alter_empty'] = FALSE;
  /* Sort criterion: Bookings: Bookings ID */
  $handler->display->display_options['sorts']['booking_id']['id'] = 'booking_id';
  $handler->display->display_options['sorts']['booking_id']['table'] = 'rooms_bookings';
  $handler->display->display_options['sorts']['booking_id']['field'] = 'booking_id';
  $handler->display->display_options['sorts']['booking_id']['order'] = 'DESC';
  /* Filter criterion: Bookings: End Date */
  $handler->display->display_options['filters']['end_date']['id'] = 'end_date';
  $handler->display->display_options['filters']['end_date']['table'] = 'rooms_bookings';
  $handler->display->display_options['filters']['end_date']['field'] = 'end_date';
  $handler->display->display_options['filters']['end_date']['operator'] = 'between';
  $handler->display->display_options['filters']['end_date']['value']['min'] = 'now';
  $handler->display->display_options['filters']['end_date']['value']['max'] = '+7 days';
  $handler->display->display_options['filters']['end_date']['value']['type'] = 'offset';
  $handler->display->display_options['filters']['end_date']['exposed'] = TRUE;
  $handler->display->display_options['filters']['end_date']['expose']['operator_id'] = 'end_date_op';
  $handler->display->display_options['filters']['end_date']['expose']['label'] = 'End Date';
  $handler->display->display_options['filters']['end_date']['expose']['operator'] = 'end_date_op';
  $handler->display->display_options['filters']['end_date']['expose']['identifier'] = 'end_date';
  /* Filter criterion: Bookings: Booking_status */
  $handler->display->display_options['filters']['booking_status']['id'] = 'booking_status';
  $handler->display->display_options['filters']['booking_status']['table'] = 'rooms_bookings';
  $handler->display->display_options['filters']['booking_status']['field'] = 'booking_status';
  $handler->display->display_options['filters']['booking_status']['value'] = array(
    0 => '0',
    1 => '1',
  );

  /* Display: Outgoing Bookings */
  $handler = $view->new_display('block', 'Outgoing Bookings', 'block_1');

  $views['outgoing_bookings'] = $view;

  return $views;
}
