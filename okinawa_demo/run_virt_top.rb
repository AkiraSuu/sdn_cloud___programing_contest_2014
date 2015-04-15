#!/usr/bin/ruby
# encoding: utf-8

require 'csv'

system 'virt-top --csv top_file2.csv --script -n 2'
csv = CSV.read('top_file2.csv')
	puts "#{csv[2][0]} #{csv[2][1]} #{csv[2][2]} #{csv[2][3]} #{csv[2][14]} #{csv[2][15]} #{csv[2][16]} #{csv[2][13]} "
	
	if csv[2][19]!=nil then
	puts "#{csv[2][19]} #{csv[2][21]} #{csv[2][23]}"
	end
	if csv[2][29]!=nil then
	puts "#{csv[2][29]} #{csv[2][31]} #{csv[2][33]}"
	end
	if csv[2][39]!=nil then
	puts "#{csv[2][39]} #{csv[2][41]} #{csv[2][43]}"
	end
	if csv[2][49]!=nil then
	puts "#{csv[2][49]} #{csv[2][51]} #{csv[2][53]}"
	end
	if csv[2][59]!=nil then
	puts "#{csv[2][59]} #{csv[2][61]} #{csv[2][63]}"
	end
	if csv[2][69]!=nil then
	puts "#{csv[2][69]} #{csv[2][71]} #{csv[2][73]}"
	end

