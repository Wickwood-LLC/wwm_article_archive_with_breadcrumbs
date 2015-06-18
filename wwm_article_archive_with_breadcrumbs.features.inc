<?php
/**
 * @file
 * wwm_article_archive_with_breadcrumbs.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function wwm_article_archive_with_breadcrumbs_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function wwm_article_archive_with_breadcrumbs_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_custom_breadcrumb_features_default_settings().
 */
function wwm_article_archive_with_breadcrumbs_custom_breadcrumb_features_default_settings() {
  $custom_breadcrumbs = array();

  // Exported custom breadcrumb: article_post.
  $custom_breadcrumbs['article_post'] = array(
    'titles' => 'Articles
[node:published:custom:Y]
[node:published:custom:F]
[node:published:custom:d]',
    'paths' => 'articles
articles/[node:published:custom:Y]
articles/[node:published:custom:Y]/[node:published:custom:m]
articles/[node:published:custom:Y]/[node:published:custom:m]/[node:published:custom:d]',
    'visibility_php' => '',
    'node_type' => 'article_post',
    'language' => '',
    'name' => 'article_post',
    'machine_name' => 'article_post',
  );

  return $custom_breadcrumbs;
}

/**
 * Implements hook_node_info().
 */
function wwm_article_archive_with_breadcrumbs_node_info() {
  $items = array(
    'article_post' => array(
      'name' => t('Article Post'),
      'base' => 'node_content',
      'description' => t('<em>Article Posts</em> are for adding content that can organized into an article directory or used as a single user blog.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
