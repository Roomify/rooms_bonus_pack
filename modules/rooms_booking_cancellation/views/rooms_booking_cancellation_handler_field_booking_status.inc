<?php

class rooms_booking_cancellation_handler_field_booking_status extends rooms_booking_handler_field_booking_status {
  function render($values) {
    if ($values->rooms_bookings_booking_status == 0) return 'Unconfirmed';
    elseif ($values->rooms_bookings_booking_status == 1) return 'Confirmed';
    elseif ($values->rooms_bookings_booking_status == 2) return 'Cancelled';

    return '';
  }
}
