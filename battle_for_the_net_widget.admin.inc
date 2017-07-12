<?php

/**
 * @file
 * Administrative page callbacks for the battle_for_the_net_widget module.
 */

/**
 * Implements hook_admin_settings() for module settings configuration.
 */
function battle_for_the_net_widget_admin_settings_form($form_state) {
    $form['general'] = array(
        '#type' => 'fieldset',
        '#title' => t('General settings'),
    );
    $form['general']['theme'] = array(
        '#type' => 'select',
        '#title' => t('Theme'),
        '#description' => t('Choose from \'default\', \'money\', \'stop\', and \'slow\''),
        '#options' => _widget_available_themes(),
        '#default_value' => variable_get('battle_for_the_net_widget_theme', 'default'),
    );
    $form['general']['organization'] = array(
        '#type' => 'select',
        '#title' => t('Organization'),
        '#description' => t('Choose from Free Press, Demand Progress, or Fight for the Future, or choose \'Random\' to randomly split form submissions between all organizations in the Battle for the Net coalition.'),
        '#options' => _widget_available_organizations(),
        '#default_value' => variable_get('battle_for_the_net_widget_organization', 'random'),
    );
    $form['general']['delay'] = array(
        '#type' => 'textfield',
        '#title' => t('Delay'),
        '#description' => t('Specify a delay (in milliseconds) before showing the widget. Default is 1 second.'),
        '#default_value' => variable_get('battle_for_the_net_widget_delay', 1000),
    );
    $today = new DateTime();
    $default_date = array(
        'year' => variable_get('battle_for_the_net_widget_date_year', $today->format('Y')),
        'month' => variable_get('battle_for_the_net_widget_date_month', $today->format('n')),
        'day' => variable_get('battle_for_the_net_widget_date_day', $today->format('j')),
    );
    $form['general']['date'] = array(
        '#type' => 'date',
        '#title' => t('Date'),
        '#description' => t('Specify a date on which to display the widget. Defaults to July 12th, 2017 if blank. Useful for testing.'),
        '#default_value' => $default_date,
    );
    $form['general']['always_show_widget'] = array(
        '#type' => 'checkbox',
        '#title' => t('Always show widget'),
        '#description' => t('Always show the widget. Useful for testing.'),
        '#default_value' => variable_get('battle_for_the_net_widget_always_show_widget', false),
    );

    // Submit button.
    $form['actions'] = array('#type' => 'actions');
    $form['actions']['submit'] = array(
        '#type' => 'submit',
        '#value' => t('Save configuration'),
    );

    return $form;
   // return system_settings_form($form);
}

/**
 * Implements hook_form_validate() for module settings configuration.
 */
function battle_for_the_net_widget_admin_settings_form_validate($form, &$form_state){
    //Do Validate-y things here...
    return;
}

/**
 * Implements hook_form_submit() for module settings configuration.
 */
function battle_for_the_net_widget_admin_settings_form_submit($form, &$form_state){
    //Store our form values
    variable_set('battle_for_the_net_widget_theme', $form_state['values']['theme']);
    variable_set('battle_for_the_net_widget_organization', $form_state['values']['organization']);
    variable_set('battle_for_the_net_widget_delay', $form_state['values']['delay']);
    variable_set('battle_for_the_net_widget_date_year', $form_state['values']['date']['year']);
    variable_set('battle_for_the_net_widget_date_month', $form_state['values']['date']['month']);
    variable_set('battle_for_the_net_widget_date_day', $form_state['values']['date']['day']);
    variable_set('battle_for_the_net_widget_always_show_widget', (bool) $form_state['values']['always_show_widget']);

    drupal_set_message(t('Successfully saved settings.'), 'status');
    return;
}

function _widget_available_themes(){
    $themes = array(
        'default' => 'Default',
        'money' => 'Money',
        'stop' => 'Stop',
        'slow' => 'Slow',
    );

    return $themes;
}

function _widget_available_organizations(){
    $organizations = array(
        'random' => 'Random',
        'fp' => 'Free Press',
        'dp' => 'Demand Progress',
        'fftf' => 'Fight for the Future',
    );

    return $organizations;
}