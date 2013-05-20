<?php

/**
 * A Helper class to add form elments into a form
 * like a hot knife in butter
 *
 * @author Amzad Hossain
 */
class butter {

  // Form Related Code
  protected $form;
  protected $main_fieldset;
  protected $weight;

  function __construct( &$form , $weight = 10 )
  {
    $this->form = &$form;
    $this->weight = $weight;
  }

  // Adds field in group
  public function addInMainContentGroup($name, $group = 'group_chart_main_content') {

    if( !isset( $this->form['#groups'][ $group ]) ) {
      return false;
    }
    $this->form['#groups'][ $group ]->children[] = $name;
    $this->form['#group_children'][$name] = $group;
  }

  /**
   * Creates Text Field
   * @param string $name   Key of Fieldset
   * @param string $legend Legend
   * @param array  $extra  Override Default Settings
   */
  public function fieldset( $name, $legend, $extra = array() ) {

    $field = array(
      '#type' => 'fieldset',
      '#title' => $legend,
      '#weight' => $this->weight++,
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
    );
    $this->form[ $name ] = $extra + $field;
    $this->addInMainContentGroup( $name );
  }

  /**
   * Creates Text Field
   * @param string $name     Key of this text field
   * @param string $fieldset Key of the fieldset that will contain this. Empty creates individual field
   * @param string $label    Label of this field
   * @param string $value    Default Value for this field
   * @param array  $extra    Override Default Settings
   */
  public function textField( $name, $fieldset = '', $label, $value = '', $extra = array()){

    $field = $extra + array(
        '#type' => 'textfield',
        '#title' => $label,
        '#default_value' => $value,
        '#weight' => $this->weight++,
      );

    if( empty($fieldset) )
    {
      $this->form[$name] = $field;
      $this->addInMainContentGroup( $name );
    }else {
      $this->form[ $fieldset ][$name] = $field;
    }
  }

  /**
   * Creates Color Field
   * @param string $name     Key of this text field
   * @param string $fieldset Key of the fieldset that will contain this. Empty creates individual field
   * @param string $label    Label of this field
   * @param string $value    Default Value for this field
   * @param array  $extra    Override Default Settings
   */
  public function colorField( $name, $fieldset = '', $label, $value = 'FFFFFF', $extra = array()){

    $field = $extra + array(
        '#type' => 'jquery_colorpicker',
        '#title' => $label,
        '#default_value' => $value,
        '#weight' => $this->weight++,
      );

    if( empty($fieldset) )
    {
      $this->form[$name] = $field;
      $this->addInMainContentGroup( $name );
    }else {
      $this->form[ $fieldset ][$name] = $field;
    }
  }

  /**
   * Creates Markup Field
   * @param string $name     Key of this text field
   * @param string $fieldset Key of the fieldset that will contain this. Empty creates individual field
   * @param string $markup   markup html
   * @param array  $extra    Override Default Settings
   */
  public function markupField( $name, $fieldset = '', $markup = '', $extra = array()){

    $field = $extra + array(
        '#markup' => $markup,
      );

    if( empty($fieldset) )
    {
      $this->form[$name] = $field;
      $this->addInMainContentGroup( $name );
    }else {
      $this->form[ $fieldset ][$name] = $field;
    }
  }

  /**
   * Creates File Field
   * @param string $name     Key of this text field
   * @param string $fieldset Key of the fieldset that will contain this. Empty creates individual field
   * @param string $label    Label of this field
   * @param boolean $required  Required
   * @param array  $extra    Override Default Settings
   */
  public function fileField( $name, $fieldset = '', $label, $required = false, $extra = array()){

    $field = $extra + array(
        '#type' => 'file',
        '#title' => $label,
        '#required' => $required,
        '#weight' => $this->weight++,
      );

    if( empty($fieldset) )
    {
      $this->form[$name] = $field;
      $this->addInMainContentGroup( $name );
    }else {
      $this->form[ $fieldset ][$name] = $field;
    }
  }

  /**
   * Creates Select Field
   * @param string $name     Key of this text field
   * @param string $fieldset Key of the fieldset that will contain this. Empty creates individual field
   * @param string $lael    Label of this field
   * @param array $options  Select Box Options
   * @param string $value    Default Value for this field
   * @param boolean $required   To make required field
   * @param array  $extra    Override Default Settings
   */
  public function selectField( $name, $fieldset = '', $label, $options = array(), $value = '', $required = false, $extra = array()){

    $field = $extra + array(
        '#type' => 'select',
        '#title' => $label,
        '#options' => $options,
        '#default_value' => $value,
        '#required' => $required,
        '#weight' => $this->weight++,
      );

    if( empty($fieldset) )
    {
      $this->form[$name] = $field;
      $this->addInMainContentGroup( $name );
    }else {
      $this->form[ $fieldset ][$name] = $field;
    }
  }

   /**
   * Creates Checkbox Field
   * @param string $name     Key of this text field
   * @param string $fieldset Key of the fieldset that will contain this. Empty creates individual field
   * @param string $label    Label of this field
   * @param string $value    Default Value for this field
   * @param array  $extra    Override Default Settings
   */
  public function checkboxField( $name, $fieldset = '', $label, $value = '', $extra = array()){

    $field = $extra + array(
        '#type' => 'checkbox',
        '#title' => $label,
        '#default_value' => $value,
        '#weight' => $this->weight++,
      );

    if( empty($fieldset) )
    {
      $this->form[$name] = $field;
      $this->addInMainContentGroup( $name );
    }else {
      $this->form[ $fieldset ][$name] = $field;
    }
  }

  /**
   * Creates Radios Field
   * @param string $name     Key of this text field
   * @param string $fieldset Key of the fieldset that will contain this. Empty creates individual field
   * @param string $label    Label of this field
   * @param array $options   Options
   * @param string $value    Default Value for this field
   * @param array  $extra    Override Default Settings
   */
  public function radiosField( $name, $fieldset = '', $label, $options = array(), $value = '', $extra = array()){

    $field = $extra + array(
        '#type' => 'radios',
        '#title' => $label,
        '#options' => $options,
        '#default_value' => $value,
        '#weight' => $this->weight++,
      );

    if( empty($fieldset) )
    {
      $this->form[$name] = $field;
      $this->addInMainContentGroup( $name );
    }else {
      $this->form[ $fieldset ][$name] = $field;
    }
  }

  /**
   * Creates Hidden Field
   * @param string $name     Key of this text field
   * @param string $value    Default Value for this field
   */
  public function hiddenField( $name, $value = ''){

    $field = array(
        '#type' => 'hidden',
        '#value' => $value,
      );

    $this->form[$name] = $field;
  }

}
