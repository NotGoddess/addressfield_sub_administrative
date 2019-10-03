<?php

/**
 * @file
 * Hide the country when only one country is available.
 */

$plugin = array(
  'title' => t('Show Sub-administrative area (County)'),
  'format callback' => 'addressfield_format_address_sub_administrative',
  'type' => 'address',
  'weight' => 0,
);

/**
 * Format callback.
 *
 * @see CALLBACK_addressfield_format_callback()
 */
function addressfield_format_address_sub_administrative(&$format, $address, $context = array()) {
  // Only add if locality_block is present.
  if (isset($format['locality_block'])) {
  
    // These fields have no #weight assignded by default.
    // However they are in the correct order for display.
    // We need to assign weights to the locality_block fields in order to place our field in the right spot.
    $weight = $extra_weight = 0;
    
    // Loop through children adding weight and inserting our field after postal_code, before administrative_area
    foreach( element_children($format['locality_block']) as $key => $value) {
    
      // Another plugin may have set weights as well - respect that when possible.      
      $weight = (isset($format['locality_block'][$value]['#weight']) && 
        $format['locality_block'][$value]['#weight'] > $weight) ? 
        $format['locality_block'][$value]['#weight'] : ++$weight;
        
      // The administrative_area field should always be present, even if disabled.
      if ($value == 'administrative_area') {
        $format['locality_block']['sub_administrative_area'] = array(
          '#title' => t('County', array(), array('context' => 'addressfield')),
          '#size' => 23,
          '#required' => TRUE,
          '#prefix' => ' ',
          '#weight' => $weight,
          '#attributes' => array('class' => array('county')),
        );
        // Set to 1 to ensure higher weight on subsequent elements.
        $extra_weight = 1;
      }
      // Assign the new weight.
      $format['locality_block'][$value]['#weight'] = $weight + $extra_weight;
    }
  }
}
