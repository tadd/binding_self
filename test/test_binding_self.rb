require 'minitest_helper'

class C
  def initialize(x)
    @x = x
  end

  def binding
    ::Kernel.binding
  end
end

class TestBindingSelf < MiniTest::Test
  def test_version_number_validity
    assert_match /^\d+\.\d+\.\d+/, Binding::Self::VERSION
  end

  def test_self
    c = C.new(42)
    assert_equal 42, c.binding.self.instance_eval { @x }
  end
end
