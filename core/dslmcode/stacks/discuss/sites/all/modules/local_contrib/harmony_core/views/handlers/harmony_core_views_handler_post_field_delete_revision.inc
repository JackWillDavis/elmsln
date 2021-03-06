<?php
/**
 * @file
 * Provide views handlers for post revisions.
 */

/**
 * Field handler to present a link node delete.
 */
class harmony_core_views_handler_post_field_delete_revision extends harmony_core_views_handler_post_field_view_revision {
  /**
   * Renders the link.
   */
  function render_link($entity, $values) {
    if (harmony_core_post_revision_access_callback('delete', $entity)) {
      $this->options['alter']['make_link'] = TRUE;
      $this->options['alter']['path'] = "post/$entity->post_id/revisions/$entity->vid/delete";
      $this->options['alter']['query'] = drupal_get_destination();

      $text = !empty($this->options['text']) ? check_plain($this->options['text']) : t('Delete');
      return $text;
    }
    else {
      $this->options['alter']['path'] = '';
    }
  }
}
