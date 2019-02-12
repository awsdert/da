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
libs = 'magic'
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
function Libs(cmd)
	if not libs then return cmd end
	for lib in Words(libs) do
		cmd = cmd .. ' -l' .. lib
	end
	return cmd
end
function Link(link,cmd)
	if False(link) then
		return cmd .. ' -c'
	end	return cmd
end
function CC(dst,link,...)
	local cmd = 'gcc -Wall'
	cmd = cmd .. ' -o "' .. dst .. '"'
	cmd = Link(link,cmd)
	for s,src in pairs({...}) do
		cmd = cmd .. ' ' .. src
	end
	return Libs(cmd)
end
function CXX(dst,link,...)
	local cmd = 'g++ -Wall'
	cmd = cmd .. ' -o "' .. dst .. '"'
	cmd = Link(link,cmd)
	for s,src in pairs({...}) do
		cmd = cmd .. ' ' .. src
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
system(CC('da_main.o',0,'da_main.c'))
system(CC('da/das.o',0,'da/das.c'))
