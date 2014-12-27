# coding: utf-8
lib = File.expand_path('../lib', __FILE__)
$LOAD_PATH.unshift(lib) unless $LOAD_PATH.include?(lib)
require 'binding_self/version'

Gem::Specification.new do |spec|
  spec.name          = "binding_self"
  spec.version       = Binding::Self::VERSION
  spec.authors       = ["Tadashi Saito"]
  spec.email         = ["tad.a.digger@gmail.com"]
  spec.extensions    = ["ext/binding_self/extconf.rb"]
  spec.summary       = %q{Binding#eval with block, without string-eval.}
  spec.homepage      = "http://github.com/tadd/binding_self"
  spec.license       = "Ruby"

  spec.files         = `git ls-files -z`.split("\x0")
  spec.test_files    = spec.files.grep(%r{^(test|spec|features)/})
  spec.require_paths = ["lib"]

  spec.add_development_dependency "bundler"
  spec.add_development_dependency "rake"
  spec.add_development_dependency "rake-compiler"
  spec.add_development_dependency "minitest"
end
