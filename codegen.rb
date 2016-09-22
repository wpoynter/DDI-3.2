#/usr/bin/ruby

require 'nokogiri'
require 'json'
require 'erb'
require 'active_support/inflector'

filepath = '/Users/williampoynter/Downloads/bundles/alspac_95_mnq/ddi.xml'


class Tag
  def initialize(name, ns)
    @name = name
    @prefix = ns.prefix
    @ns = ns.href
    
    @children = []
    @has_content = false
    @attributes = []
    @repeatable = !([
    'Title', 'PublicationDate', 'String', 'Text',
    'URN', 'ID', 'Agency', 'LiteralText', 'Description',
    'TypeOfObject',
    'Version'].include?(@name))
  end
  
  def name
    @name
  end
  
  def scoped_name
    @prefix + ':' + @name
  end
  
  def has_content= new_val
    @has_content = new_val
  end
  
  def has_content?
    @has_content
  end
  
  def tidy
    @children.uniq!
    @attributes.uniq!
    
    if @children.count > 0 && @children[0] == 'text'
      @children.shift
    end
  end
  
  def children
    @children
  end
  
  def children=(new_val)
    @children = new_val
  end
  
  def attributes
    @attributes
  end
  
  def get_binding
    binding()
  end
  
  def repeatable
    @repeatable
  end
end

doc = open(filepath) { |f| Nokogiri::XML(f) }

schema = []

doc.xpath('//*').each do |x|
  schema << Tag.new(x.name, x.namespace)
end

schema.uniq! { |x| x.scoped_name }

schema.each do |t|
  doc.xpath('//'+t.scoped_name).each do |x|
    if x.children.count > 0
      if x.children.count == 1 && x.children[0].name == 'text'
        t.has_content = true
      else
        x.children.each do |c|
         t.children << c.name
        end
      end
    end
    
    x.attributes.keys.each do |a|
      t.attributes << a
    end
  end
  t.tidy
  
  tmp = []
  t.children.each do |c|
    tags = schema.select{ |x| x.name == c }
    tmp << {name: c, repeatable: tags[0].repeatable, scoped_name: tags[0].scoped_name}
  end
  t.children = tmp
end

unless Dir.exist? 'src/classes'
  Dir.mkdir 'src/classes'
end 

header = ERB.new(File.read('header.erb'), nil, '<>')
source = ERB.new(File.read('source.erb'), nil, '<>')

schema.each do |s|
  hdr = File.open 'src/classes/' + s.name.downcase + '.hpp', 'w'
  hdr.puts header.result(s.get_binding)
  hdr.close
  
  src = File.open 'src/classes/' + s.name.downcase + '.cpp', 'w'
  src.puts source.result(s.get_binding)
  src.close
end