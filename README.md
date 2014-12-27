# Binding#self

Binding#self to extract self of the binding.

## Installation

Add this line to your application's Gemfile:

```ruby
gem 'binding_self'
```

And then execute:

    $ bundle

Or install it yourself as:

    $ gem install binding_self

## Usage

```ruby
require 'binding_self'

class Foo
  def initialize(a)
    @ivar = a
  end

  def binding
    ::Kernel.binding
  end
end

foo = Foo.new(2)
foo.binding.self #=> #<Foo:0x00000012345678 @ivar=2>
foo.binding.self.instance_eval { @ivar } #=> 2
```


## Contributing

1. Fork it ( https://github.com/tadd/binding_self/fork )
2. Create your feature branch (`git checkout -b my-new-feature`)
3. Commit your changes (`git commit -am 'Add some feature'`)
4. Push to the branch (`git push origin my-new-feature`)
5. Create a new Pull Request!

## License

Ruby's.  See COPYING and BSDL.
