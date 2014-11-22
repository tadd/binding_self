require 'minitest_helper'

class TestBindingEvalWithBlock < MiniTest::Unit::TestCase
  def test_version_number_validity
    assert_match /^\d\.\d\.\d$/, Binding::EvalWithBlock::VERSION
  end
end
