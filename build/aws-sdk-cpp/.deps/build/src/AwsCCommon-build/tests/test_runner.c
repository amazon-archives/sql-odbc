#include <ctype.h>  /* NOLINT */
#include <stdio.h>  /* NOLINT */
#include <stdlib.h> /* NOLINT */
#include <string.h> /* NOLINT */

#if defined(_MSC_VER)
#pragma warning(disable : 4996) /* deprecation */
#endif



/* Forward declare test functions. */
int raise_errors_test(int, char*[]);
int reset_errors_test(int, char*[]);
int error_callback_test(int, char*[]);
int unknown_error_code_in_slot_test(int, char*[]);
int unknown_error_code_no_slot_test(int, char*[]);
int unknown_error_code_range_too_large_test(int, char*[]);
int aws_load_error_strings_test(int, char*[]);
int aws_assume_compiles_test(int, char*[]);
int thread_creation_join_test(int, char*[]);
int thread_atexit_test(int, char*[]);
int mutex_aquire_release_test(int, char*[]);
int mutex_is_actually_mutex_test(int, char*[]);
int conditional_notify_one(int, char*[]);
int conditional_notify_all(int, char*[]);
int error_code_cross_thread_test(int, char*[]);
int high_res_clock_increments_test(int, char*[]);
int sys_clock_increments_test(int, char*[]);
int test_sec_and_millis_conversions(int, char*[]);
int test_sec_and_micros_conversions(int, char*[]);
int test_sec_and_nanos_conversions(int, char*[]);
int test_milli_and_micros_conversion(int, char*[]);
int test_milli_and_nanos_conversion(int, char*[]);
int test_micro_and_nanos_conversion(int, char*[]);
int test_precision_loss_remainders_conversion(int, char*[]);
int test_overflow_conversion(int, char*[]);
int array_list_order_push_back_pop_front_test(int, char*[]);
int array_list_order_push_back_pop_back_test(int, char*[]);
int array_list_pop_front_n_test(int, char*[]);
int array_list_erase_test(int, char*[]);
int array_list_exponential_mem_model_test(int, char*[]);
int array_list_exponential_mem_model_iteration_test(int, char*[]);
int array_list_set_at_overwrite_safety(int, char*[]);
int array_list_iteration_by_ptr_test(int, char*[]);
int array_list_iteration_test(int, char*[]);
int array_list_preallocated_iteration_test(int, char*[]);
int array_list_preallocated_push_test(int, char*[]);
int array_list_shrink_to_fit_test(int, char*[]);
int array_list_shrink_to_fit_static_test(int, char*[]);
int array_list_clear_test(int, char*[]);
int array_list_copy_test(int, char*[]);
int array_list_swap_contents_test(int, char*[]);
int array_list_not_enough_space_test(int, char*[]);
int array_list_not_enough_space_test_failure(int, char*[]);
int array_list_of_strings_sort(int, char*[]);
int array_list_empty_sort(int, char*[]);
int priority_queue_push_pop_order_test(int, char*[]);
int priority_queue_random_values_test(int, char*[]);
int priority_queue_size_and_capacity_test(int, char*[]);
int priority_queue_remove_root_test(int, char*[]);
int priority_queue_remove_leaf_test(int, char*[]);
int priority_queue_remove_interior_sift_up_test(int, char*[]);
int priority_queue_remove_interior_sift_down_test(int, char*[]);
int linked_list_push_back_pop_front(int, char*[]);
int linked_list_push_front_pop_back(int, char*[]);
int linked_list_swap_nodes(int, char*[]);
int linked_list_iteration(int, char*[]);
int linked_list_reverse_iteration(int, char*[]);
int linked_list_swap_contents(int, char*[]);
int hex_encoding_test_case_empty_test(int, char*[]);
int hex_encoding_test_case_f_test(int, char*[]);
int hex_encoding_test_case_fo_test(int, char*[]);
int hex_encoding_test_case_foo_test(int, char*[]);
int hex_encoding_test_case_foob_test(int, char*[]);
int hex_encoding_test_case_fooba_test(int, char*[]);
int hex_encoding_test_case_foobar_test(int, char*[]);
int hex_encoding_test_case_missing_leading_zero(int, char*[]);
int hex_encoding_invalid_buffer_size_test(int, char*[]);
int hex_encoding_highbyte_string_test(int, char*[]);
int hex_encoding_overflow_test(int, char*[]);
int hex_encoding_invalid_string_test(int, char*[]);
int hex_encoding_append_dynamic_test_case_empty(int, char*[]);
int hex_encoding_append_dynamic_test_case_fooba(int, char*[]);
int base64_encoding_test_case_empty_test(int, char*[]);
int base64_encoding_test_case_f_test(int, char*[]);
int base64_encoding_test_case_fo_test(int, char*[]);
int base64_encoding_test_case_foo_test(int, char*[]);
int base64_encoding_test_case_foob_test(int, char*[]);
int base64_encoding_test_case_fooba_test(int, char*[]);
int base64_encoding_test_case_foobar_test(int, char*[]);
int base64_encoding_test_case_32bytes_test(int, char*[]);
int base64_encoding_buffer_size_too_small_test(int, char*[]);
int base64_encoding_buffer_size_overflow_test(int, char*[]);
int base64_encoding_buffer_size_invalid_test(int, char*[]);
int base64_encoding_invalid_buffer_test(int, char*[]);
int base64_encoding_highbyte_string_test(int, char*[]);
int base64_encoding_invalid_padding_test(int, char*[]);
int base64_encoding_test_zeros(int, char*[]);
int base64_encoding_test_roundtrip(int, char*[]);
int base64_encoding_test_all_values(int, char*[]);
int uint64_buffer_test(int, char*[]);
int uint64_buffer_non_aligned_test(int, char*[]);
int uint32_buffer_test(int, char*[]);
int uint32_buffer_non_aligned_test(int, char*[]);
int uint24_buffer_test(int, char*[]);
int uint24_buffer_non_aligned_test(int, char*[]);
int uint16_buffer_test(int, char*[]);
int uint16_buffer_non_aligned_test(int, char*[]);
int uint16_buffer_signed_positive_test(int, char*[]);
int uint16_buffer_signed_negative_test(int, char*[]);
int scheduler_cleanup_cancellation(int, char*[]);
int scheduler_ordering_test(int, char*[]);
int scheduler_pops_task_late_test(int, char*[]);
int scheduler_has_tasks_test(int, char*[]);
int scheduler_reentrant_safe(int, char*[]);
int scheduler_cleanup_reentrants(int, char*[]);
int scheduler_oom_still_works(int, char*[]);
int scheduler_schedule_cancellation(int, char*[]);
int scheduler_cleanup_idempotent(int, char*[]);
int scheduler_oom_during_init(int, char*[]);
int test_hash_table_create_find(int, char*[]);
int test_hash_table_string_create_find(int, char*[]);
int test_hash_table_put(int, char*[]);
int test_hash_table_put_null_dtor(int, char*[]);
int test_hash_table_swap_move(int, char*[]);
int test_hash_table_string_clean_up(int, char*[]);
int test_hash_table_hash_collision(int, char*[]);
int test_hash_table_hash_overwrite(int, char*[]);
int test_hash_table_hash_remove(int, char*[]);
int test_hash_table_hash_clear_allows_cleanup(int, char*[]);
int test_hash_table_on_resize_returns_correct_entry(int, char*[]);
int test_hash_table_foreach(int, char*[]);
int test_hash_table_iter(int, char*[]);
int test_hash_table_empty_iter(int, char*[]);
int test_hash_table_iter_detail(int, char*[]);
int test_hash_table_eq(int, char*[]);
int test_hash_churn(int, char*[]);
int test_hash_table_cleanup_idempotent(int, char*[]);
int test_hash_table_byte_cursor_create_find(int, char*[]);
int test_is_power_of_two(int, char*[]);
int test_round_up_to_power_of_two(int, char*[]);
int test_mul_size_checked(int, char*[]);
int test_mul_size_saturating(int, char*[]);
int test_mul_u32_checked(int, char*[]);
int test_mul_u32_saturating(int, char*[]);
int test_mul_u64_checked(int, char*[]);
int test_mul_u64_saturating(int, char*[]);
int test_add_size_checked(int, char*[]);
int test_aws_add_size_checked_varargs(int, char*[]);
int test_add_size_saturating(int, char*[]);
int test_add_u32_checked(int, char*[]);
int test_add_u32_saturating(int, char*[]);
int test_add_u64_checked(int, char*[]);
int test_add_u64_saturating(int, char*[]);
int nospec_index_test(int, char*[]);
int test_byte_cursor_advance(int, char*[]);
int test_byte_cursor_advance_nospec(int, char*[]);
int byte_cursor_write_tests(int, char*[]);
int byte_cursor_read_tests(int, char*[]);
int byte_cursor_limit_tests(int, char*[]);
int test_byte_cursor_right_trim_empty(int, char*[]);
int test_byte_cursor_right_trim_all_whitespace(int, char*[]);
int test_byte_cursor_right_trim_basic(int, char*[]);
int test_byte_cursor_left_trim_empty(int, char*[]);
int test_byte_cursor_left_trim_all_whitespace(int, char*[]);
int test_byte_cursor_left_trim_basic(int, char*[]);
int test_byte_cursor_trim_basic(int, char*[]);
int string_tests(int, char*[]);
int binary_string_test(int, char*[]);
int string_compare_test(int, char*[]);
int string_destroy_secure_test(int, char*[]);
int secure_strlen_test(int, char*[]);
int test_char_split_happy_path(int, char*[]);
int test_char_split_ends_with_token(int, char*[]);
int test_char_split_token_not_present(int, char*[]);
int test_char_split_empty(int, char*[]);
int test_char_split_adj_tokens(int, char*[]);
int test_char_split_begins_with_token(int, char*[]);
int test_char_split_with_max_splits(int, char*[]);
int test_char_split_output_too_small(int, char*[]);
int test_buffer_cat(int, char*[]);
int test_buffer_cat_dest_too_small(int, char*[]);
int test_buffer_cpy(int, char*[]);
int test_buffer_cpy_dest_too_small(int, char*[]);
int test_buffer_cpy_offsets(int, char*[]);
int test_buffer_cpy_offsets_dest_too_small(int, char*[]);
int test_buffer_eq(int, char*[]);
int test_buffer_eq_same_content_different_len(int, char*[]);
int test_buffer_eq_null_internal_byte_buffer(int, char*[]);
int test_buffer_init_copy(int, char*[]);
int test_buffer_init_copy_null_buffer(int, char*[]);
int test_buffer_advance(int, char*[]);
int test_buffer_printf(int, char*[]);
int test_array_eq(int, char*[]);
int test_array_eq_ignore_case(int, char*[]);
int test_array_eq_c_str(int, char*[]);
int test_array_eq_c_str_ignore_case(int, char*[]);
int test_array_hash_ignore_case(int, char*[]);
int test_byte_buf_append_dynamic(int, char*[]);
int test_byte_buf_append_lookup_success(int, char*[]);
int test_byte_buf_append_lookup_failure(int, char*[]);
int test_byte_buf_reserve(int, char*[]);
int test_byte_buf_reserve_relative(int, char*[]);
int test_byte_buf_reset(int, char*[]);
int test_byte_cursor_compare_lexical(int, char*[]);
int test_byte_cursor_compare_lookup(int, char*[]);
int byte_swap_test(int, char*[]);
int alignment_test(int, char*[]);
int test_cpu_count_at_least_works_superficially(int, char*[]);
int test_stack_trace_decoding(int, char*[]);
int test_realloc_fallback(int, char*[]);
int test_realloc_fallback_oom(int, char*[]);
int test_realloc_passthrough(int, char*[]);
int test_realloc_passthrough_oom(int, char*[]);
int test_cf_allocator_wrapper(int, char*[]);
int test_acquire_many(int, char*[]);
int test_alloc_nothing(int, char*[]);
int test_calloc_override(int, char*[]);
int test_calloc_fallback_from_default_allocator(int, char*[]);
int test_calloc_fallback_from_given(int, char*[]);
int test_calloc_from_default_allocator(int, char*[]);
int test_calloc_from_given_allocator(int, char*[]);
int timebomb_allocator(int, char*[]);
int test_lru_cache_overflow_static_members(int, char*[]);
int test_lru_cache_lru_ness_static_members(int, char*[]);
int test_lru_cache_entries_cleanup(int, char*[]);
int test_lru_cache_overwrite(int, char*[]);
int test_lru_cache_element_access_members(int, char*[]);
int rw_lock_aquire_release_test(int, char*[]);
int rw_lock_is_actually_rw_lock_test(int, char*[]);
int rw_lock_many_readers_test(int, char*[]);
int test_secure_zero(int, char*[]);
int test_buffer_secure_zero(int, char*[]);
int test_buffer_clean_up_secure(int, char*[]);
int is_zeroed(int, char*[]);
int atomics_semantics(int, char*[]);
int atomics_semantics_implicit(int, char*[]);
int atomics_static_init(int, char*[]);
int atomics_loads_reordered_with_older_stores(int, char*[]);
int atomics_acquire_to_release_one_direction(int, char*[]);
int atomics_acquire_to_release_mixed(int, char*[]);
int rfc822_utc_parsing(int, char*[]);
int rfc822_utc_parsing_auto_detect(int, char*[]);
int rfc822_local_time_east_of_gmt_parsing(int, char*[]);
int rfc822_local_time_west_of_gmt_parsing(int, char*[]);
int rfc822_utc_two_digit_year_parsing(int, char*[]);
int rfc822_utc_no_dow_parsing(int, char*[]);
int rfc822_utc_dos_prevented(int, char*[]);
int rfc822_invalid_format(int, char*[]);
int rfc822_invalid_tz(int, char*[]);
int rfc822_invalid_auto_format(int, char*[]);
int iso8601_utc_parsing(int, char*[]);
int iso8601_basic_utc_parsing(int, char*[]);
int iso8601_utc_parsing_auto_detect(int, char*[]);
int iso8601_basic_utc_parsing_auto_detect(int, char*[]);
int iso8601_date_only_parsing(int, char*[]);
int iso8601_basic_date_only_parsing(int, char*[]);
int iso8601_utc_no_colon_parsing(int, char*[]);
int iso8601_utc_dos_prevented(int, char*[]);
int iso8601_invalid_format(int, char*[]);
int iso8601_invalid_auto_format(int, char*[]);
int unix_epoch_parsing(int, char*[]);
int millis_parsing(int, char*[]);
int device_rand_u64_distribution(int, char*[]);
int device_rand_u32_distribution(int, char*[]);
int device_rand_u16_distribution(int, char*[]);
int device_rand_buffer_distribution(int, char*[]);
int uuid_string(int, char*[]);
int prefilled_uuid_string(int, char*[]);
int uuid_string_short_buffer(int, char*[]);
int uuid_string_parse(int, char*[]);
int uuid_string_parse_too_short(int, char*[]);
int uuid_string_parse_malformed(int, char*[]);
int test_environment_functions(int, char*[]);
int short_argument_parse(int, char*[]);
int long_argument_parse(int, char*[]);
int unqualified_argument_parse(int, char*[]);
int unknown_argument_parse(int, char*[]);
int ring_buffer_1_to_1_acquire_release_wraps_test(int, char*[]);
int ring_buffer_release_after_full_test(int, char*[]);
int ring_buffer_acquire_up_to_test(int, char*[]);
int ring_buffer_acquire_tail_always_chases_head_test(int, char*[]);
int ring_buffer_acquire_multi_threaded_test(int, char*[]);
int ring_buffer_acquire_up_to_multi_threaded_test(int, char*[]);
int ring_buffer_allocator_test(int, char*[]);
int test_logging_filter_at_AWS_LL_NONE_s_logf_all_levels(int, char*[]);
int test_logging_filter_at_AWS_LL_FATAL_s_logf_all_levels(int, char*[]);
int test_logging_filter_at_AWS_LL_ERROR_s_logf_all_levels(int, char*[]);
int test_logging_filter_at_AWS_LL_WARN_s_logf_all_levels(int, char*[]);
int test_logging_filter_at_AWS_LL_INFO_s_logf_all_levels(int, char*[]);
int test_logging_filter_at_AWS_LL_DEBUG_s_logf_all_levels(int, char*[]);
int test_logging_filter_at_AWS_LL_TRACE_s_logf_all_levels(int, char*[]);
int test_logging_filter_at_AWS_LL_TRACE_s_logf_all_levels_trace_cutoff(int, char*[]);
int test_logging_filter_at_AWS_LL_TRACE_s_logf_all_levels_debug_cutoff(int, char*[]);
int test_logging_filter_at_AWS_LL_TRACE_s_logf_all_levels_info_cutoff(int, char*[]);
int test_logging_filter_at_AWS_LL_TRACE_s_logf_all_levels_warn_cutoff(int, char*[]);
int test_logging_filter_at_AWS_LL_TRACE_s_logf_all_levels_error_cutoff(int, char*[]);
int test_logging_filter_at_AWS_LL_TRACE_s_logf_all_levels_fatal_cutoff(int, char*[]);
int test_logging_filter_at_AWS_LL_TRACE_s_logf_all_levels_none_cutoff(int, char*[]);
int test_log_formatter_s_formatter_empty_case(int, char*[]);
int test_log_formatter_s_formatter_simple_case(int, char*[]);
int test_log_formatter_s_formatter_number_case(int, char*[]);
int test_log_formatter_s_formatter_string_case(int, char*[]);
int test_log_formatter_s_formatter_newline_case(int, char*[]);
int test_log_writer_simple_file_test(int, char*[]);
int test_log_writer_existing_file_test(int, char*[]);
int test_log_writer_bad_file_test(int, char*[]);
int test_foreground_log_channel_single_line(int, char*[]);
int test_foreground_log_channel_numbers(int, char*[]);
int test_foreground_log_channel_words(int, char*[]);
int test_foreground_log_channel_all(int, char*[]);
int test_background_log_channel_single_line(int, char*[]);
int test_background_log_channel_numbers(int, char*[]);
int test_background_log_channel_words(int, char*[]);
int test_background_log_channel_all(int, char*[]);
int test_pipeline_logger_unformatted_test(int, char*[]);
int test_pipeline_logger_formatted_test(int, char*[]);


#ifdef __cplusplus
#  define CM_CAST(TYPE, EXPR) static_cast<TYPE>(EXPR)
#  if __cplusplus >= 201103L
#    define CM_NULL nullptr
#  else
#    define CM_NULL NULL
#  endif
#else
#  define CM_CAST(TYPE, EXPR) (TYPE)(EXPR)
#  define CM_NULL NULL
#endif

/* Create map.  */

typedef int (*MainFuncPointer)(int, char* []); /* NOLINT */
typedef struct /* NOLINT */
{
  const char* name;
  MainFuncPointer func;
} functionMapEntry;

static functionMapEntry cmakeGeneratedFunctionMapEntries[] = {
    {
    "raise_errors_test",
    raise_errors_test
  },
  {
    "reset_errors_test",
    reset_errors_test
  },
  {
    "error_callback_test",
    error_callback_test
  },
  {
    "unknown_error_code_in_slot_test",
    unknown_error_code_in_slot_test
  },
  {
    "unknown_error_code_no_slot_test",
    unknown_error_code_no_slot_test
  },
  {
    "unknown_error_code_range_too_large_test",
    unknown_error_code_range_too_large_test
  },
  {
    "aws_load_error_strings_test",
    aws_load_error_strings_test
  },
  {
    "aws_assume_compiles_test",
    aws_assume_compiles_test
  },
  {
    "thread_creation_join_test",
    thread_creation_join_test
  },
  {
    "thread_atexit_test",
    thread_atexit_test
  },
  {
    "mutex_aquire_release_test",
    mutex_aquire_release_test
  },
  {
    "mutex_is_actually_mutex_test",
    mutex_is_actually_mutex_test
  },
  {
    "conditional_notify_one",
    conditional_notify_one
  },
  {
    "conditional_notify_all",
    conditional_notify_all
  },
  {
    "error_code_cross_thread_test",
    error_code_cross_thread_test
  },
  {
    "high_res_clock_increments_test",
    high_res_clock_increments_test
  },
  {
    "sys_clock_increments_test",
    sys_clock_increments_test
  },
  {
    "test_sec_and_millis_conversions",
    test_sec_and_millis_conversions
  },
  {
    "test_sec_and_micros_conversions",
    test_sec_and_micros_conversions
  },
  {
    "test_sec_and_nanos_conversions",
    test_sec_and_nanos_conversions
  },
  {
    "test_milli_and_micros_conversion",
    test_milli_and_micros_conversion
  },
  {
    "test_milli_and_nanos_conversion",
    test_milli_and_nanos_conversion
  },
  {
    "test_micro_and_nanos_conversion",
    test_micro_and_nanos_conversion
  },
  {
    "test_precision_loss_remainders_conversion",
    test_precision_loss_remainders_conversion
  },
  {
    "test_overflow_conversion",
    test_overflow_conversion
  },
  {
    "array_list_order_push_back_pop_front_test",
    array_list_order_push_back_pop_front_test
  },
  {
    "array_list_order_push_back_pop_back_test",
    array_list_order_push_back_pop_back_test
  },
  {
    "array_list_pop_front_n_test",
    array_list_pop_front_n_test
  },
  {
    "array_list_erase_test",
    array_list_erase_test
  },
  {
    "array_list_exponential_mem_model_test",
    array_list_exponential_mem_model_test
  },
  {
    "array_list_exponential_mem_model_iteration_test",
    array_list_exponential_mem_model_iteration_test
  },
  {
    "array_list_set_at_overwrite_safety",
    array_list_set_at_overwrite_safety
  },
  {
    "array_list_iteration_by_ptr_test",
    array_list_iteration_by_ptr_test
  },
  {
    "array_list_iteration_test",
    array_list_iteration_test
  },
  {
    "array_list_preallocated_iteration_test",
    array_list_preallocated_iteration_test
  },
  {
    "array_list_preallocated_push_test",
    array_list_preallocated_push_test
  },
  {
    "array_list_shrink_to_fit_test",
    array_list_shrink_to_fit_test
  },
  {
    "array_list_shrink_to_fit_static_test",
    array_list_shrink_to_fit_static_test
  },
  {
    "array_list_clear_test",
    array_list_clear_test
  },
  {
    "array_list_copy_test",
    array_list_copy_test
  },
  {
    "array_list_swap_contents_test",
    array_list_swap_contents_test
  },
  {
    "array_list_not_enough_space_test",
    array_list_not_enough_space_test
  },
  {
    "array_list_not_enough_space_test_failure",
    array_list_not_enough_space_test_failure
  },
  {
    "array_list_of_strings_sort",
    array_list_of_strings_sort
  },
  {
    "array_list_empty_sort",
    array_list_empty_sort
  },
  {
    "priority_queue_push_pop_order_test",
    priority_queue_push_pop_order_test
  },
  {
    "priority_queue_random_values_test",
    priority_queue_random_values_test
  },
  {
    "priority_queue_size_and_capacity_test",
    priority_queue_size_and_capacity_test
  },
  {
    "priority_queue_remove_root_test",
    priority_queue_remove_root_test
  },
  {
    "priority_queue_remove_leaf_test",
    priority_queue_remove_leaf_test
  },
  {
    "priority_queue_remove_interior_sift_up_test",
    priority_queue_remove_interior_sift_up_test
  },
  {
    "priority_queue_remove_interior_sift_down_test",
    priority_queue_remove_interior_sift_down_test
  },
  {
    "linked_list_push_back_pop_front",
    linked_list_push_back_pop_front
  },
  {
    "linked_list_push_front_pop_back",
    linked_list_push_front_pop_back
  },
  {
    "linked_list_swap_nodes",
    linked_list_swap_nodes
  },
  {
    "linked_list_iteration",
    linked_list_iteration
  },
  {
    "linked_list_reverse_iteration",
    linked_list_reverse_iteration
  },
  {
    "linked_list_swap_contents",
    linked_list_swap_contents
  },
  {
    "hex_encoding_test_case_empty_test",
    hex_encoding_test_case_empty_test
  },
  {
    "hex_encoding_test_case_f_test",
    hex_encoding_test_case_f_test
  },
  {
    "hex_encoding_test_case_fo_test",
    hex_encoding_test_case_fo_test
  },
  {
    "hex_encoding_test_case_foo_test",
    hex_encoding_test_case_foo_test
  },
  {
    "hex_encoding_test_case_foob_test",
    hex_encoding_test_case_foob_test
  },
  {
    "hex_encoding_test_case_fooba_test",
    hex_encoding_test_case_fooba_test
  },
  {
    "hex_encoding_test_case_foobar_test",
    hex_encoding_test_case_foobar_test
  },
  {
    "hex_encoding_test_case_missing_leading_zero",
    hex_encoding_test_case_missing_leading_zero
  },
  {
    "hex_encoding_invalid_buffer_size_test",
    hex_encoding_invalid_buffer_size_test
  },
  {
    "hex_encoding_highbyte_string_test",
    hex_encoding_highbyte_string_test
  },
  {
    "hex_encoding_overflow_test",
    hex_encoding_overflow_test
  },
  {
    "hex_encoding_invalid_string_test",
    hex_encoding_invalid_string_test
  },
  {
    "hex_encoding_append_dynamic_test_case_empty",
    hex_encoding_append_dynamic_test_case_empty
  },
  {
    "hex_encoding_append_dynamic_test_case_fooba",
    hex_encoding_append_dynamic_test_case_fooba
  },
  {
    "base64_encoding_test_case_empty_test",
    base64_encoding_test_case_empty_test
  },
  {
    "base64_encoding_test_case_f_test",
    base64_encoding_test_case_f_test
  },
  {
    "base64_encoding_test_case_fo_test",
    base64_encoding_test_case_fo_test
  },
  {
    "base64_encoding_test_case_foo_test",
    base64_encoding_test_case_foo_test
  },
  {
    "base64_encoding_test_case_foob_test",
    base64_encoding_test_case_foob_test
  },
  {
    "base64_encoding_test_case_fooba_test",
    base64_encoding_test_case_fooba_test
  },
  {
    "base64_encoding_test_case_foobar_test",
    base64_encoding_test_case_foobar_test
  },
  {
    "base64_encoding_test_case_32bytes_test",
    base64_encoding_test_case_32bytes_test
  },
  {
    "base64_encoding_buffer_size_too_small_test",
    base64_encoding_buffer_size_too_small_test
  },
  {
    "base64_encoding_buffer_size_overflow_test",
    base64_encoding_buffer_size_overflow_test
  },
  {
    "base64_encoding_buffer_size_invalid_test",
    base64_encoding_buffer_size_invalid_test
  },
  {
    "base64_encoding_invalid_buffer_test",
    base64_encoding_invalid_buffer_test
  },
  {
    "base64_encoding_highbyte_string_test",
    base64_encoding_highbyte_string_test
  },
  {
    "base64_encoding_invalid_padding_test",
    base64_encoding_invalid_padding_test
  },
  {
    "base64_encoding_test_zeros",
    base64_encoding_test_zeros
  },
  {
    "base64_encoding_test_roundtrip",
    base64_encoding_test_roundtrip
  },
  {
    "base64_encoding_test_all_values",
    base64_encoding_test_all_values
  },
  {
    "uint64_buffer_test",
    uint64_buffer_test
  },
  {
    "uint64_buffer_non_aligned_test",
    uint64_buffer_non_aligned_test
  },
  {
    "uint32_buffer_test",
    uint32_buffer_test
  },
  {
    "uint32_buffer_non_aligned_test",
    uint32_buffer_non_aligned_test
  },
  {
    "uint24_buffer_test",
    uint24_buffer_test
  },
  {
    "uint24_buffer_non_aligned_test",
    uint24_buffer_non_aligned_test
  },
  {
    "uint16_buffer_test",
    uint16_buffer_test
  },
  {
    "uint16_buffer_non_aligned_test",
    uint16_buffer_non_aligned_test
  },
  {
    "uint16_buffer_signed_positive_test",
    uint16_buffer_signed_positive_test
  },
  {
    "uint16_buffer_signed_negative_test",
    uint16_buffer_signed_negative_test
  },
  {
    "scheduler_cleanup_cancellation",
    scheduler_cleanup_cancellation
  },
  {
    "scheduler_ordering_test",
    scheduler_ordering_test
  },
  {
    "scheduler_pops_task_late_test",
    scheduler_pops_task_late_test
  },
  {
    "scheduler_has_tasks_test",
    scheduler_has_tasks_test
  },
  {
    "scheduler_reentrant_safe",
    scheduler_reentrant_safe
  },
  {
    "scheduler_cleanup_reentrants",
    scheduler_cleanup_reentrants
  },
  {
    "scheduler_oom_still_works",
    scheduler_oom_still_works
  },
  {
    "scheduler_schedule_cancellation",
    scheduler_schedule_cancellation
  },
  {
    "scheduler_cleanup_idempotent",
    scheduler_cleanup_idempotent
  },
  {
    "scheduler_oom_during_init",
    scheduler_oom_during_init
  },
  {
    "test_hash_table_create_find",
    test_hash_table_create_find
  },
  {
    "test_hash_table_string_create_find",
    test_hash_table_string_create_find
  },
  {
    "test_hash_table_put",
    test_hash_table_put
  },
  {
    "test_hash_table_put_null_dtor",
    test_hash_table_put_null_dtor
  },
  {
    "test_hash_table_swap_move",
    test_hash_table_swap_move
  },
  {
    "test_hash_table_string_clean_up",
    test_hash_table_string_clean_up
  },
  {
    "test_hash_table_hash_collision",
    test_hash_table_hash_collision
  },
  {
    "test_hash_table_hash_overwrite",
    test_hash_table_hash_overwrite
  },
  {
    "test_hash_table_hash_remove",
    test_hash_table_hash_remove
  },
  {
    "test_hash_table_hash_clear_allows_cleanup",
    test_hash_table_hash_clear_allows_cleanup
  },
  {
    "test_hash_table_on_resize_returns_correct_entry",
    test_hash_table_on_resize_returns_correct_entry
  },
  {
    "test_hash_table_foreach",
    test_hash_table_foreach
  },
  {
    "test_hash_table_iter",
    test_hash_table_iter
  },
  {
    "test_hash_table_empty_iter",
    test_hash_table_empty_iter
  },
  {
    "test_hash_table_iter_detail",
    test_hash_table_iter_detail
  },
  {
    "test_hash_table_eq",
    test_hash_table_eq
  },
  {
    "test_hash_churn",
    test_hash_churn
  },
  {
    "test_hash_table_cleanup_idempotent",
    test_hash_table_cleanup_idempotent
  },
  {
    "test_hash_table_byte_cursor_create_find",
    test_hash_table_byte_cursor_create_find
  },
  {
    "test_is_power_of_two",
    test_is_power_of_two
  },
  {
    "test_round_up_to_power_of_two",
    test_round_up_to_power_of_two
  },
  {
    "test_mul_size_checked",
    test_mul_size_checked
  },
  {
    "test_mul_size_saturating",
    test_mul_size_saturating
  },
  {
    "test_mul_u32_checked",
    test_mul_u32_checked
  },
  {
    "test_mul_u32_saturating",
    test_mul_u32_saturating
  },
  {
    "test_mul_u64_checked",
    test_mul_u64_checked
  },
  {
    "test_mul_u64_saturating",
    test_mul_u64_saturating
  },
  {
    "test_add_size_checked",
    test_add_size_checked
  },
  {
    "test_aws_add_size_checked_varargs",
    test_aws_add_size_checked_varargs
  },
  {
    "test_add_size_saturating",
    test_add_size_saturating
  },
  {
    "test_add_u32_checked",
    test_add_u32_checked
  },
  {
    "test_add_u32_saturating",
    test_add_u32_saturating
  },
  {
    "test_add_u64_checked",
    test_add_u64_checked
  },
  {
    "test_add_u64_saturating",
    test_add_u64_saturating
  },
  {
    "nospec_index_test",
    nospec_index_test
  },
  {
    "test_byte_cursor_advance",
    test_byte_cursor_advance
  },
  {
    "test_byte_cursor_advance_nospec",
    test_byte_cursor_advance_nospec
  },
  {
    "byte_cursor_write_tests",
    byte_cursor_write_tests
  },
  {
    "byte_cursor_read_tests",
    byte_cursor_read_tests
  },
  {
    "byte_cursor_limit_tests",
    byte_cursor_limit_tests
  },
  {
    "test_byte_cursor_right_trim_empty",
    test_byte_cursor_right_trim_empty
  },
  {
    "test_byte_cursor_right_trim_all_whitespace",
    test_byte_cursor_right_trim_all_whitespace
  },
  {
    "test_byte_cursor_right_trim_basic",
    test_byte_cursor_right_trim_basic
  },
  {
    "test_byte_cursor_left_trim_empty",
    test_byte_cursor_left_trim_empty
  },
  {
    "test_byte_cursor_left_trim_all_whitespace",
    test_byte_cursor_left_trim_all_whitespace
  },
  {
    "test_byte_cursor_left_trim_basic",
    test_byte_cursor_left_trim_basic
  },
  {
    "test_byte_cursor_trim_basic",
    test_byte_cursor_trim_basic
  },
  {
    "string_tests",
    string_tests
  },
  {
    "binary_string_test",
    binary_string_test
  },
  {
    "string_compare_test",
    string_compare_test
  },
  {
    "string_destroy_secure_test",
    string_destroy_secure_test
  },
  {
    "secure_strlen_test",
    secure_strlen_test
  },
  {
    "test_char_split_happy_path",
    test_char_split_happy_path
  },
  {
    "test_char_split_ends_with_token",
    test_char_split_ends_with_token
  },
  {
    "test_char_split_token_not_present",
    test_char_split_token_not_present
  },
  {
    "test_char_split_empty",
    test_char_split_empty
  },
  {
    "test_char_split_adj_tokens",
    test_char_split_adj_tokens
  },
  {
    "test_char_split_begins_with_token",
    test_char_split_begins_with_token
  },
  {
    "test_char_split_with_max_splits",
    test_char_split_with_max_splits
  },
  {
    "test_char_split_output_too_small",
    test_char_split_output_too_small
  },
  {
    "test_buffer_cat",
    test_buffer_cat
  },
  {
    "test_buffer_cat_dest_too_small",
    test_buffer_cat_dest_too_small
  },
  {
    "test_buffer_cpy",
    test_buffer_cpy
  },
  {
    "test_buffer_cpy_dest_too_small",
    test_buffer_cpy_dest_too_small
  },
  {
    "test_buffer_cpy_offsets",
    test_buffer_cpy_offsets
  },
  {
    "test_buffer_cpy_offsets_dest_too_small",
    test_buffer_cpy_offsets_dest_too_small
  },
  {
    "test_buffer_eq",
    test_buffer_eq
  },
  {
    "test_buffer_eq_same_content_different_len",
    test_buffer_eq_same_content_different_len
  },
  {
    "test_buffer_eq_null_internal_byte_buffer",
    test_buffer_eq_null_internal_byte_buffer
  },
  {
    "test_buffer_init_copy",
    test_buffer_init_copy
  },
  {
    "test_buffer_init_copy_null_buffer",
    test_buffer_init_copy_null_buffer
  },
  {
    "test_buffer_advance",
    test_buffer_advance
  },
  {
    "test_buffer_printf",
    test_buffer_printf
  },
  {
    "test_array_eq",
    test_array_eq
  },
  {
    "test_array_eq_ignore_case",
    test_array_eq_ignore_case
  },
  {
    "test_array_eq_c_str",
    test_array_eq_c_str
  },
  {
    "test_array_eq_c_str_ignore_case",
    test_array_eq_c_str_ignore_case
  },
  {
    "test_array_hash_ignore_case",
    test_array_hash_ignore_case
  },
  {
    "test_byte_buf_append_dynamic",
    test_byte_buf_append_dynamic
  },
  {
    "test_byte_buf_append_lookup_success",
    test_byte_buf_append_lookup_success
  },
  {
    "test_byte_buf_append_lookup_failure",
    test_byte_buf_append_lookup_failure
  },
  {
    "test_byte_buf_reserve",
    test_byte_buf_reserve
  },
  {
    "test_byte_buf_reserve_relative",
    test_byte_buf_reserve_relative
  },
  {
    "test_byte_buf_reset",
    test_byte_buf_reset
  },
  {
    "test_byte_cursor_compare_lexical",
    test_byte_cursor_compare_lexical
  },
  {
    "test_byte_cursor_compare_lookup",
    test_byte_cursor_compare_lookup
  },
  {
    "byte_swap_test",
    byte_swap_test
  },
  {
    "alignment_test",
    alignment_test
  },
  {
    "test_cpu_count_at_least_works_superficially",
    test_cpu_count_at_least_works_superficially
  },
  {
    "test_stack_trace_decoding",
    test_stack_trace_decoding
  },
  {
    "test_realloc_fallback",
    test_realloc_fallback
  },
  {
    "test_realloc_fallback_oom",
    test_realloc_fallback_oom
  },
  {
    "test_realloc_passthrough",
    test_realloc_passthrough
  },
  {
    "test_realloc_passthrough_oom",
    test_realloc_passthrough_oom
  },
  {
    "test_cf_allocator_wrapper",
    test_cf_allocator_wrapper
  },
  {
    "test_acquire_many",
    test_acquire_many
  },
  {
    "test_alloc_nothing",
    test_alloc_nothing
  },
  {
    "test_calloc_override",
    test_calloc_override
  },
  {
    "test_calloc_fallback_from_default_allocator",
    test_calloc_fallback_from_default_allocator
  },
  {
    "test_calloc_fallback_from_given",
    test_calloc_fallback_from_given
  },
  {
    "test_calloc_from_default_allocator",
    test_calloc_from_default_allocator
  },
  {
    "test_calloc_from_given_allocator",
    test_calloc_from_given_allocator
  },
  {
    "timebomb_allocator",
    timebomb_allocator
  },
  {
    "test_lru_cache_overflow_static_members",
    test_lru_cache_overflow_static_members
  },
  {
    "test_lru_cache_lru_ness_static_members",
    test_lru_cache_lru_ness_static_members
  },
  {
    "test_lru_cache_entries_cleanup",
    test_lru_cache_entries_cleanup
  },
  {
    "test_lru_cache_overwrite",
    test_lru_cache_overwrite
  },
  {
    "test_lru_cache_element_access_members",
    test_lru_cache_element_access_members
  },
  {
    "rw_lock_aquire_release_test",
    rw_lock_aquire_release_test
  },
  {
    "rw_lock_is_actually_rw_lock_test",
    rw_lock_is_actually_rw_lock_test
  },
  {
    "rw_lock_many_readers_test",
    rw_lock_many_readers_test
  },
  {
    "test_secure_zero",
    test_secure_zero
  },
  {
    "test_buffer_secure_zero",
    test_buffer_secure_zero
  },
  {
    "test_buffer_clean_up_secure",
    test_buffer_clean_up_secure
  },
  {
    "is_zeroed",
    is_zeroed
  },
  {
    "atomics_semantics",
    atomics_semantics
  },
  {
    "atomics_semantics_implicit",
    atomics_semantics_implicit
  },
  {
    "atomics_static_init",
    atomics_static_init
  },
  {
    "atomics_loads_reordered_with_older_stores",
    atomics_loads_reordered_with_older_stores
  },
  {
    "atomics_acquire_to_release_one_direction",
    atomics_acquire_to_release_one_direction
  },
  {
    "atomics_acquire_to_release_mixed",
    atomics_acquire_to_release_mixed
  },
  {
    "rfc822_utc_parsing",
    rfc822_utc_parsing
  },
  {
    "rfc822_utc_parsing_auto_detect",
    rfc822_utc_parsing_auto_detect
  },
  {
    "rfc822_local_time_east_of_gmt_parsing",
    rfc822_local_time_east_of_gmt_parsing
  },
  {
    "rfc822_local_time_west_of_gmt_parsing",
    rfc822_local_time_west_of_gmt_parsing
  },
  {
    "rfc822_utc_two_digit_year_parsing",
    rfc822_utc_two_digit_year_parsing
  },
  {
    "rfc822_utc_no_dow_parsing",
    rfc822_utc_no_dow_parsing
  },
  {
    "rfc822_utc_dos_prevented",
    rfc822_utc_dos_prevented
  },
  {
    "rfc822_invalid_format",
    rfc822_invalid_format
  },
  {
    "rfc822_invalid_tz",
    rfc822_invalid_tz
  },
  {
    "rfc822_invalid_auto_format",
    rfc822_invalid_auto_format
  },
  {
    "iso8601_utc_parsing",
    iso8601_utc_parsing
  },
  {
    "iso8601_basic_utc_parsing",
    iso8601_basic_utc_parsing
  },
  {
    "iso8601_utc_parsing_auto_detect",
    iso8601_utc_parsing_auto_detect
  },
  {
    "iso8601_basic_utc_parsing_auto_detect",
    iso8601_basic_utc_parsing_auto_detect
  },
  {
    "iso8601_date_only_parsing",
    iso8601_date_only_parsing
  },
  {
    "iso8601_basic_date_only_parsing",
    iso8601_basic_date_only_parsing
  },
  {
    "iso8601_utc_no_colon_parsing",
    iso8601_utc_no_colon_parsing
  },
  {
    "iso8601_utc_dos_prevented",
    iso8601_utc_dos_prevented
  },
  {
    "iso8601_invalid_format",
    iso8601_invalid_format
  },
  {
    "iso8601_invalid_auto_format",
    iso8601_invalid_auto_format
  },
  {
    "unix_epoch_parsing",
    unix_epoch_parsing
  },
  {
    "millis_parsing",
    millis_parsing
  },
  {
    "device_rand_u64_distribution",
    device_rand_u64_distribution
  },
  {
    "device_rand_u32_distribution",
    device_rand_u32_distribution
  },
  {
    "device_rand_u16_distribution",
    device_rand_u16_distribution
  },
  {
    "device_rand_buffer_distribution",
    device_rand_buffer_distribution
  },
  {
    "uuid_string",
    uuid_string
  },
  {
    "prefilled_uuid_string",
    prefilled_uuid_string
  },
  {
    "uuid_string_short_buffer",
    uuid_string_short_buffer
  },
  {
    "uuid_string_parse",
    uuid_string_parse
  },
  {
    "uuid_string_parse_too_short",
    uuid_string_parse_too_short
  },
  {
    "uuid_string_parse_malformed",
    uuid_string_parse_malformed
  },
  {
    "test_environment_functions",
    test_environment_functions
  },
  {
    "short_argument_parse",
    short_argument_parse
  },
  {
    "long_argument_parse",
    long_argument_parse
  },
  {
    "unqualified_argument_parse",
    unqualified_argument_parse
  },
  {
    "unknown_argument_parse",
    unknown_argument_parse
  },
  {
    "ring_buffer_1_to_1_acquire_release_wraps_test",
    ring_buffer_1_to_1_acquire_release_wraps_test
  },
  {
    "ring_buffer_release_after_full_test",
    ring_buffer_release_after_full_test
  },
  {
    "ring_buffer_acquire_up_to_test",
    ring_buffer_acquire_up_to_test
  },
  {
    "ring_buffer_acquire_tail_always_chases_head_test",
    ring_buffer_acquire_tail_always_chases_head_test
  },
  {
    "ring_buffer_acquire_multi_threaded_test",
    ring_buffer_acquire_multi_threaded_test
  },
  {
    "ring_buffer_acquire_up_to_multi_threaded_test",
    ring_buffer_acquire_up_to_multi_threaded_test
  },
  {
    "ring_buffer_allocator_test",
    ring_buffer_allocator_test
  },
  {
    "test_logging_filter_at_AWS_LL_NONE_s_logf_all_levels",
    test_logging_filter_at_AWS_LL_NONE_s_logf_all_levels
  },
  {
    "test_logging_filter_at_AWS_LL_FATAL_s_logf_all_levels",
    test_logging_filter_at_AWS_LL_FATAL_s_logf_all_levels
  },
  {
    "test_logging_filter_at_AWS_LL_ERROR_s_logf_all_levels",
    test_logging_filter_at_AWS_LL_ERROR_s_logf_all_levels
  },
  {
    "test_logging_filter_at_AWS_LL_WARN_s_logf_all_levels",
    test_logging_filter_at_AWS_LL_WARN_s_logf_all_levels
  },
  {
    "test_logging_filter_at_AWS_LL_INFO_s_logf_all_levels",
    test_logging_filter_at_AWS_LL_INFO_s_logf_all_levels
  },
  {
    "test_logging_filter_at_AWS_LL_DEBUG_s_logf_all_levels",
    test_logging_filter_at_AWS_LL_DEBUG_s_logf_all_levels
  },
  {
    "test_logging_filter_at_AWS_LL_TRACE_s_logf_all_levels",
    test_logging_filter_at_AWS_LL_TRACE_s_logf_all_levels
  },
  {
    "test_logging_filter_at_AWS_LL_TRACE_s_logf_all_levels_trace_cutoff",
    test_logging_filter_at_AWS_LL_TRACE_s_logf_all_levels_trace_cutoff
  },
  {
    "test_logging_filter_at_AWS_LL_TRACE_s_logf_all_levels_debug_cutoff",
    test_logging_filter_at_AWS_LL_TRACE_s_logf_all_levels_debug_cutoff
  },
  {
    "test_logging_filter_at_AWS_LL_TRACE_s_logf_all_levels_info_cutoff",
    test_logging_filter_at_AWS_LL_TRACE_s_logf_all_levels_info_cutoff
  },
  {
    "test_logging_filter_at_AWS_LL_TRACE_s_logf_all_levels_warn_cutoff",
    test_logging_filter_at_AWS_LL_TRACE_s_logf_all_levels_warn_cutoff
  },
  {
    "test_logging_filter_at_AWS_LL_TRACE_s_logf_all_levels_error_cutoff",
    test_logging_filter_at_AWS_LL_TRACE_s_logf_all_levels_error_cutoff
  },
  {
    "test_logging_filter_at_AWS_LL_TRACE_s_logf_all_levels_fatal_cutoff",
    test_logging_filter_at_AWS_LL_TRACE_s_logf_all_levels_fatal_cutoff
  },
  {
    "test_logging_filter_at_AWS_LL_TRACE_s_logf_all_levels_none_cutoff",
    test_logging_filter_at_AWS_LL_TRACE_s_logf_all_levels_none_cutoff
  },
  {
    "test_log_formatter_s_formatter_empty_case",
    test_log_formatter_s_formatter_empty_case
  },
  {
    "test_log_formatter_s_formatter_simple_case",
    test_log_formatter_s_formatter_simple_case
  },
  {
    "test_log_formatter_s_formatter_number_case",
    test_log_formatter_s_formatter_number_case
  },
  {
    "test_log_formatter_s_formatter_string_case",
    test_log_formatter_s_formatter_string_case
  },
  {
    "test_log_formatter_s_formatter_newline_case",
    test_log_formatter_s_formatter_newline_case
  },
  {
    "test_log_writer_simple_file_test",
    test_log_writer_simple_file_test
  },
  {
    "test_log_writer_existing_file_test",
    test_log_writer_existing_file_test
  },
  {
    "test_log_writer_bad_file_test",
    test_log_writer_bad_file_test
  },
  {
    "test_foreground_log_channel_single_line",
    test_foreground_log_channel_single_line
  },
  {
    "test_foreground_log_channel_numbers",
    test_foreground_log_channel_numbers
  },
  {
    "test_foreground_log_channel_words",
    test_foreground_log_channel_words
  },
  {
    "test_foreground_log_channel_all",
    test_foreground_log_channel_all
  },
  {
    "test_background_log_channel_single_line",
    test_background_log_channel_single_line
  },
  {
    "test_background_log_channel_numbers",
    test_background_log_channel_numbers
  },
  {
    "test_background_log_channel_words",
    test_background_log_channel_words
  },
  {
    "test_background_log_channel_all",
    test_background_log_channel_all
  },
  {
    "test_pipeline_logger_unformatted_test",
    test_pipeline_logger_unformatted_test
  },
  {
    "test_pipeline_logger_formatted_test",
    test_pipeline_logger_formatted_test
  },

  { CM_NULL, CM_NULL } /* NOLINT */
};

static const int NumTests = CM_CAST(int,
  sizeof(cmakeGeneratedFunctionMapEntries) / sizeof(functionMapEntry)) - 1;

/* Allocate and create a lowercased copy of string
   (note that it has to be free'd manually) */
static char* lowercase(const char* string)
{
  char *new_string, *p;
  size_t stringSize;

  stringSize = CM_CAST(size_t, strlen(string) + 1);
  new_string = CM_CAST(char*, malloc(sizeof(char) * stringSize));

  if (new_string == CM_NULL) { /* NOLINT */
    return CM_NULL;            /* NOLINT */
  }
  strcpy(new_string, string);  /* NOLINT */
  for (p = new_string; *p != 0; ++p) {
    *p = CM_CAST(char, tolower(*p));
  }
  return new_string;
}

int main(int ac, char* av[])
{
  int i, testNum = 0, partial_match;
  char *arg;
  int testToRun = -1;

  

  /* If no test name was given */
  /* process command line with user function.  */
  if (ac < 2) {
    /* Ask for a test.  */
    printf("Available tests:\n");
    for (i = 0; i < NumTests; ++i) {
      printf("%3d. %s\n", i, cmakeGeneratedFunctionMapEntries[i].name);
    }
    printf("To run a test, enter the test number: ");
    fflush(stdout);
    if (scanf("%d", &testNum) != 1) {
      printf("Couldn't parse that input as a number\n");
      return -1;
    }
    if (testNum >= NumTests) {
      printf("%3d is an invalid test number.\n", testNum);
      return -1;
    }
    testToRun = testNum;
    ac--;
    av++;
  }
  partial_match = 0;
  arg = CM_NULL; /* NOLINT */
  /* If partial match is requested.  */
  if (testToRun == -1 && ac > 1) {
    partial_match = (strcmp(av[1], "-R") == 0) ? 1 : 0;
  }
  if (partial_match != 0 && ac < 3) {
    printf("-R needs an additional parameter.\n");
    return -1;
  }
  if (testToRun == -1) {
    arg = lowercase(av[1 + partial_match]);
  }
  for (i = 0; i < NumTests && testToRun == -1; ++i) {
    char *test_name = lowercase(cmakeGeneratedFunctionMapEntries[i].name);
    if (partial_match != 0 && strstr(test_name, arg) != CM_NULL) { /* NOLINT */
      testToRun = i;
      ac -= 2;
      av += 2;
    } else if (partial_match == 0 && strcmp(test_name, arg) == 0) {
      testToRun = i;
      ac--;
      av++;
    }
    free(test_name);
  }
  free(arg);
  if (testToRun != -1) {
    int result;

    if (testToRun < 0 || testToRun >= NumTests) {
      printf("testToRun was modified by TestDriver code to an invalid value: "
             "%3d.\n",
             testNum);
      return -1;
    }
    result = (*cmakeGeneratedFunctionMapEntries[testToRun].func)(ac, av);

    return result;
  }

  /* Nothing was run, display the test names.  */
  printf("Available tests:\n");
  for (i = 0; i < NumTests; ++i) {
    printf("%3d. %s\n", i, cmakeGeneratedFunctionMapEntries[i].name);
  }
  printf("Failed: %s is an invalid test name.\n", av[1]);

  return -1;
}
