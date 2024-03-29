set number
syntax on
let g:mapleader=";"
set ruler
set nocompatible
set mouse=a
set scrolloff=8

"自动重加载
set autoread

"设置折叠
set fdm=marker

"设置TAB和缩进宽度
set tabstop=4
set shiftwidth=4

"修改后自动加载vimrc
autocmd! bufwritepost .vimrc source %
autocmd! bufwritepost vimrc source %

"命令补全与提示
set wildmenu
set wildmode=full

"设置默认剪切板
set clipboard=unnamedplus
let g:clipboard = {
	  \   'name': 'SystemClipboard',
	  \   'copy': {
	  \      '+': 'xclip -i -selection clipboard',
	  \      '*': 'xclip -i -selection clipboard',
	  \    },
	  \   'paste': {
	  \      '+': 'xclip -o -selection clipboard',
	  \      '*': 'xclip -o -selection clipboard',
	  \   },
	  \   'cache_enabled': 1,
	  \ }

"设置退格功能
set backspace=2

"设置编码
set fileencodings=utf-8,ucs-bom,gb18030,gbk,gb2312,cp936
set fileencoding=utf-8
set termencoding=utf-8
set encoding=utf-8

"光标形状
let &t_SI.="\e[5 q" "插入模式光标
let &t_SR.="\e[4 q" "替换模式光标
let &t_EI.="\e[1 q" "正常模式光标

"安装的插件
call plug#begin('~/.vim/my_plugins/')

"快速补全HTML
Plug 'mattn/emmet-vim'

"NERD注释
Plug 'scrooloose/nerdcommenter'

"Solarize主题
Plug 'altercation/vim-colors-solarized'

"gruvbox主题
Plug 'morhetz/gruvbox'

"NERDTree 文件管理
Plug 'scrooloose/nerdtree'

"C/C++高亮增强
Plug 'octol/vim-cpp-enhanced-highlight'

"自由编写
Plug 'junegunn/goyo.vim'
Plug 'amix/vim-zenroom2'

"美化状态栏
Plug 'vim-airline/vim-airline'

"大项目模糊查找
Plug 'kien/ctrlp.vim'

"括号补全
Plug 'Raimondi/delimitMate'

"显示缩进
Plug 'Yggdroot/indentLine'

"单词下划线
"Plug 'itchyny/vim-cursorword'

"快速符号包围
Plug 'tpope/vim-surround'

"异步语法检查
Plug 'dense-analysis/ale'

"代码大纲
Plug 'majutsushi/tagbar'

"自动补全
Plug 'neoclide/coc.nvim', {'branch': 'release'}

"MarkDown
Plug 'godlygeek/tabular'
Plug 'plasticboy/vim-markdown'
Plug 'iamcco/markdown-preview.nvim', { 'do': { -> mkdp#util#install() } }


call plug#end()

"多光标
nmap <silent> <C-c> <Plug>(coc-cursors-position)
nmap <silent> <C-d> <Plug>(coc-cursors-word)
xmap <silent> <C-d> <Plug>(coc-cursors-range)
" use normal command like `<leader>xi(`
nmap <leader>x  <Plug>(coc-cursors-operator)

"设置主题
set background=dark
colorscheme gruvbox
hi Normal guibg=NONE ctermbg=NONE

"MarkDown 设置
let g:vim_markdown_frontmatter = 1
let g:mkdp_auto_start = 1
let g:vim_markdown_folding_disabled = 1

"自动补全设置
" function! s:check_back_space() abort
" let col = col('.') - 1
" return !col || getline('.')[col - 1]  =~# '\s'
" endfunction

" inoremap <silent><expr> <TAB>
"       \ pumvisible() ? coc#_select_confirm() :
"       \ coc#expandableOrJumpable() ? "\<C-r>=coc#rpc#request('doKeymap', ['snippets-expand-jump',''])\<CR>" :
"       \ <SID>check_back_space() ? "\<TAB>" :
"       \ coc#refresh()

" let g:coc_snippet_next = '<tab>'

" nmap <leader>rn <Plug>(coc-rename)
set signcolumn=number " 在行号的位置提醒错误

" 配置tab和shift tab对候选词进行选取

" <TAB> to select candidate forward or
" pump completion candidate
" 使用tab键向下选择自动补全的候选词
inoremap <silent><expr> <TAB>
      \ coc#pum#visible() ? coc#pum#next(1) :
      \ CheckBackspace() ? "\<Tab>" :
      \ coc#refresh()
" <s-TAB> to select candidate backward
" 使用shift+tab向上选择自动补全的候选词
inoremap <expr><S-TAB> coc#pum#visible() ? coc#pum#prev(1) : "\<C-h>"

" Make <CR> to accept selected completion item or notify coc.nvim to format
" <C-g>u breaks current undo, please make your own choice.
" 按回车键确认我们所选择的候选词
inoremap <silent><expr> <CR> coc#pum#visible() ? coc#pum#confirm()
                              \: "\<C-g>u\<CR>\<c-r>=coc#on_enter()\<CR>"

function! CheckBackspace() abort
  let col = col('.') - 1
  return !col || getline('.')[col - 1]  =~# '\s'
endfunction

"语法检查设置
let g:ale_fix_on_save = 1
let g:ale_lint_on_insert_leave = 1
let g:ale_linters = {
\   'c++': ['gcc'],
\   'c': ['gcc'],
\   'python': ['pylint'],
\}
let g:ale_sign_column_always = 1
let g:ale_set_highlights = 1
let g:ale_sign_error = 'E'
let g:ale_sign_warning = 'W'

"C/C++函数/类高亮
let g:cpp_class_scope_highlight = 1
let g:cpp_member_variable_highlight = 1
let g:cpp_class_decl_highlight = 1
let g:cpp_experimental_simple_template_highlight = 1
let g:cpp_concepts_highlight = 1
let c_no_curly_error=1

"缩进设置
set cindent

"按键映射----------------------------------------------------------------------

"取消高亮
nnoremap <Leader><CR> :noh<CR>

"语法检查映射
nnoremap <C-n> :ALENextWrap<CR>
nnoremap <C-m> :ALEPreviousWrap<CR>
nnoremap <Leader>d :ALEDetail<CR>

"函数跳转
nmap <silent> gd <Plug>(coc-definition)
nmap <silent> gy <Plug>(coc-type-definition)
nmap <silent> gi <Plug>(coc-implementation)
nmap <silent> gr <Plug>(coc-references)

"重命名
nmap <leader>rn <Plug>(coc-rename)

"挂起代码大纲
nnoremap <F8> :TagbarToggle<CR>

"窗口切换
map <C-j> <C-W>j
map <C-k> <C-W>k
map <C-h> <C-W>h
map <C-l> <C-W>l

"标签管理
map <leader>tn :tabnew<cr>
map <leader>h gT
map <leader>l gt

"符号包围
vnoremap (( <esc>`>a)<esc>`<i(<esc>
vnoremap << <esc>`>a><esc>`<i<<esc>
vnoremap [[ <esc>`>a]<esc>`<i[<esc>
vnoremap {{ <esc>`>a}<esc>`<i{<esc>
vnoremap "" <esc>`>a"<esc>`<i"<esc>
vnoremap '' <esc>`>a'<esc>`<i'<esc>
vnoremap `` <esc>`>a"<esc>`<i"<esc>

"可视化查找
vmap / y/<C-R>"<CR>
vmap ? y/<C-R>"<CR>
xnoremap * :<C-u>call <SID>VSetSearch('/')<CR>/<C-R>=@/<CR><CR> 
xnoremap # :<C-u>call <SID>VSetSearch('?')<CR>?<C-R>=@/<CR><CR>

function! s:VSetSearch(cmdtype)
  let temp = @s
  norm! gv"sy
  let @/ = '\V' . substitute(escape(@s, a:cmdtype.'\'), '\n', '\\n', 'g') 
  let @s = temp
endfunction

"NERDTree
map <leader>nn :NERDTreeToggle<cr>
map <leader>nb :NERDTreeFromBookmark
map <leader>nf :NERDTreeFind<cr>

"Zenroom
nnoremap <silent> <leader>z :Goyo<cr>

"MarkDown
nmap <m-s> <Plug>MarkdownPreviewStop
nmap <m-p> <Plug>MarkdownPreview
nmap <m-t> <Plug>MarkdownPreviewToggle

"ESC映射
inoremap jj <esc>
cnoremap jj <esc>

"终端快速跳转
tnoremap <C-h> <C-w>h
tnoremap <C-j> <C-w>j
tnoremap <C-k> <C-w>k
tnoremap <C-l> <C-w>l

"终端结束
tnoremap :q<CR> exit<CR>
