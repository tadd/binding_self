# Binding#eval with block

Enables to write Binding#eval with block, without string-eval.

## Installation

Add this line to your application's Gemfile:

```ruby
gem 'binding_eval_with_block'
```

And then execute:

    $ bundle

Or install it yourself as:

    $ gem install binding_eval_with_block

## Usage

```ruby
class Foo
  def initialize(a)
    @a = a
  end

  def binding
    binding
  end
end

a = 1
binding.eval { a } #=> 1

foo = Foo.new(2)
foo.binding.eval { @ivar } #=> 2
foo.binding.eval("@ivar") #=> 2, compatible behavior as usual
```


## Contributing

1. Fork it ( https://github.com/tadd/binding_eval_with_block/fork )
2. Create your feature branch (`git checkout -b my-new-feature`)
3. Commit your changes (`git commit -am 'Add some feature'`)
4. Push to the branch (`git push origin my-new-feature`)
5. Create a new Pull Request!

## License

Ruby's.  See COPYING and BSDL.
