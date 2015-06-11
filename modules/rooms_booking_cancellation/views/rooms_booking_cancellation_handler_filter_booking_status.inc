<?php

class rooms_booking_cancellation_handler_filter_booking_status extends rooms_booking_handler_filter_booking_status {
  function get_value_options() {
    $options = array(
      '0' => 'Unconfirmed',
      '1' => 'Confirmed',
      '2' => 'Cancelled',
    );

    $this->value_options = $options;
  } 
}
