var _bftn_options = {};

/*
 * Choose from 'money', 'stop', and 'slow'. Omit this property to get the
 * default theme.
 */
if(Drupal.settings.battle_for_the_net_widget_settings.theme !== 'default') {
    _bftn_options.theme = Drupal.settings.battle_for_the_net_widget_settings.theme; // @type {string}
}

/*
 * Choose from 'fp' for Free Press, 'dp' for Demand Progress or
 * 'fftf' for Fight for the Future. Omit this property to randomly split
 * form submissions between all organizations in the Battle for the Net
 * coalition.
 */
if(Drupal.settings.battle_for_the_net_widget_settings.organization !== 'random') {
    _bftn_options.org = Drupal.settings.battle_for_the_net_widget_settings.organization; // @type {string}
}


/*
 * Specify a delay (in milliseconds) before showing the widget. Defaults to one
 * second.
 */
_bftn_options.delay = Drupal.settings.battle_for_the_net_widget_settings.delay; // @type {number}


/*
 * Specify a date on which to display the widget. Defaults to July 12th, 2017 if
 * omitted. ISO-8601 dates are UTC time, three-argument dates (with a zero-based
 * month) are local time.
 */
_bftn_options.date = new Date(
    Drupal.settings.battle_for_the_net_widget_settings.date.year,
    Drupal.settings.battle_for_the_net_widget_settings.date.month - 1,
    Drupal.settings.battle_for_the_net_widget_settings.date.day
); // @type {Date}



/*
 * Always show the widget. Useful for testing.
 */
_bftn_options.always_show_widget = Drupal.settings.battle_for_the_net_widget_settings.always_show_widget; // @type {Boolean}
