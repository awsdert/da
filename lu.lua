function True(val)
	return (val == true or val == 1 or val == 'true' or val == '1')
end
function False(val)
	return (True(val) ~= true)
end
function Words(str)
	return str:gmatch('%S+')
end
function Split(str,sep)
	str = str .. sep
	local match = str:gmatch('(.-)'..sep)
	return function()
		return match()
	end
end
nsys = Lu.uname()
for i,v in pairs(nsys) do
	print( '(Lu.uname()).' .. i .. ' = ' .. v )
end
defines = 'DA_REG=da/test'
kdir = '/usr/src/kernels/' .. nsys.release
ldir = '/lib/modules/' .. nsys.release .. '/build'
nsys.domainname = nsys.domainname or ''
if nsys.sysname == "Windows" then
	nsys.cmdvar = function(var) return '%' .. var .. '%' end
	nsys.cmdset = function(var,val)
		return 'set ' .. var .. '=' .. val
	end
	nsys.cmdfun = function(name,script)
		return ':' .. name .. '\n' .. script .. '\n goto :eof'
	end
else
	nsys.cmdvar = function(var) return '${' .. var .. '}' end
	nsys.cmdset = function(var,val)
		return 'export ' .. var .. '=' .. val
	end
	nsys.cmdfun = function(name,script)
		return name .. '() {\n' .. script .. '\n}'
	end
end
function Srcs(cmd)
	if not srcs then return cmd end
	for src in Words(srcs) do
		cmd = cmd .. ' -L' .. src .. ''
	end
	return cmd
end
function Libs(cmd)
	if not libs then return cmd end
	for lib in Words(libs) do
		cmd = cmd .. ' -l' .. lib
	end
	return cmd
end
function Defines(cmd)
	if not defines then return cmd end
	for define in Words(defines) do
		cmd = cmd .. ' -D' .. define
	end
	return cmd
end
function Link(link,cmd)
	if False(link) then
		return cmd .. ' -c'
	end	return cmd
end
function CC(dst,link,...)
	local cmd = 'gcc -Wall' .. Defines('') .. Srcs('')
	cmd = cmd .. ' -o "' .. dst .. '"'
	cmd = Link(link,cmd)
	for s,src in pairs({...}) do
		if type(src) == 'table' then
			for i,v in pairs(src) do
				cmd = cmd .. ' "' .. v .. '"'
			end
		else
			cmd = cmd .. ' "' .. src .. '"'
		end
	end
	return Libs(cmd)
end
function CXX(dst,link,...)
	local cmd = 'g++ -Wall' .. Defines('') .. Srcs('')
	cmd = cmd .. ' -o "' .. dst .. '"'
	cmd = Link(link,cmd)
	for s,src in pairs({...}) do
		if type(src) == 'table' then
			for i,v in pairs(src) do
				cmd = cmd .. ' "' .. v .. '"'
			end
		else
			cmd = cmd .. ' "' .. src .. '"'
		end
	end
	return Libs(cmd)
end
function system(cmd,envp)
	local env = ''
	if envp then
		for var,val in pairs(envp) do
			env = env .. '\n' .. nsys.cmdset(var,val)
		end
		env = env:sub(2)
	end
	print(cmd)
	return Lu.system(cmd)
end
if exists('objs') == false then mkdir('objs') end
if exists('objs/da') == false then mkdir('objs/da') end
src_list='da_main.c entry.c'
for ent in iwildcard('da/*.c') do
	src_list = src_list .. ' da/' .. ent.d_name
end
obj_list = ''
obj = ''
local cd = 'cd "' .. ldir .. '"\n'
local HERE = Lu.getcwd()
local here = HERE .. '/'
local into = Lu.setcwd(ldir)
print(here)
print(into)
local err = 0
for src in Words(src_list) do
	obj = here .. 'objs/' .. src .. '.o'
	err = system((CC(obj,0,here .. src)))
	if err ~= 0 then break end
end
if err == 0 then
	system((CC(here .. 'objs/da_test.ko',1,obj_list)))
end
