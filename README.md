butter
======

A buttery wrapper for Drupal Form array. From codeigniter experience I always looked for a wrapper class to handle form generation. After digging for an alternate I created this simple class.

Check the sourcecode for more helper function. Include the file in your module and you can do this:

In form alter:

    function example_form_alter(&$form, &$form_state){

      $_form = new butter($form); // Optionally you can pass weight in 2nd parameter default 10

      $f = "fieldset_1";
      $_form->fieldset( $f, "Personal Information" );
      $_form->textField( 'f_name', $f, 'First Name', '' );
      $_form->textField( 'l_name', $f, 'Last Name',  'Value' );
      $_form->checkboxField( 'opt_out', $f, 'Opt out', true);

      return $form;
    }


Same way you can generate new form etc. Love to hear your idea or pointers. Feel free to extend it.



