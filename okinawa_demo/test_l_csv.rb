#!/usr/bin/ruby

#explain csv file 2s
# encoding: utf-8
require 'csv'
	system 'virt-top --csv top_file.csv --script -n 3'
	csv = CSV.read('top_file.csv')
	puts "#{csv.first[0]} : #{csv.first[13]}" 
	puts "#{csv[3][0]} : #{csv[3][13]}"
	puts ''
	
	puts "#{csv.first[19]} : #{csv.first[21]} : #{csv.first[23]}"
	if csv[3][19]!=nil then
	puts "#{csv[3][19]} : #{csv[3][21]}: #{csv[3][23]}"
	end
	if csv[3][29]!=nil then
	puts "#{csv[3][29]} : #{csv[3][31]}: #{csv[3][33]}"
	end
	if csv[3][39]!=nil then
	puts "#{csv[3][39]} : #{csv[3][41]}: #{csv[3][43]}"
	end
	if csv[3][49]!=nil then
	puts "#{csv[3][49]} : #{csv[3][51]}: #{csv[3][53]}"
	end
	if csv[3][59]!=nil then
	puts "#{csv[3][59]} : #{csv[3][61]}: #{csv[3][63]}"
	end
	if csv[3][69]!=nil then
	puts "#{csv[3][69]} : #{csv[3][71]}: #{csv[3][73]}"
	end
	puts "over"
























