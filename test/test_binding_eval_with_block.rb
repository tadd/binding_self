require 'minitest_helper'

class TestBindingEvalWithBlock < MiniTest::Test
  def test_version_number_validity
    assert_match /^\d\.\d\.\d$/, Binding::EvalWithBlock::VERSION
  end

  def test_internal_alias_method_set
    assert_includes Binding.instance_methods(false), :_eval_original
  end
end
