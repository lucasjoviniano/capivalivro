desc 'Compila o livro em diferentes formatos'
task :default do
  system('asciidoctor -o output/capivalivro.html index.adoc')
  system('asciidoctor-pdf -o output/capivalivro.pdf index.adoc')
end
