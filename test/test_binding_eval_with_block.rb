require 'minitest_helper'

class TestBindingEvalWithBlock < MiniTest::Test
  def test_version_number_validity
    assert_match /^\d+\.\d+\.\d+/, Binding::EvalWithBlock::VERSION
  end

  def test_internal_alias_method_set
    assert_includes Binding.instance_methods(false), :_eval_original
  end

  def test_nothing_raised_with_block_without_any_arguments
    binding.eval {}
    assert true
  end

  def test_compatible_with_string_eval
    assert_equal 1, binding.eval('1')
  end
end
