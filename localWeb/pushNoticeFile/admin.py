from django.contrib import admin
# Register your models here.

from .models import Game, NoticeCfg, NoticeLog, SshCfg, CdnCfg

# class ChoiceInline(admin.TabularInline):
#     model = Choice
#     extra = 3

# class QuestionAdmin(admin.ModelAdmin):

#     list_filter = ['pub_date']
#     list_display = ('question_text', 'pub_date', 'was_published_recently')
#     fieldsets = [
#         ("text",             {'fields':['question_text']}),
#         ('Date information', {'fields':['pub_date']}),
#     ]
#     inlines = [ChoiceInline]
#     search_fields = ['question_text']

class GameInline(admin.TabularInline):
    model = Game
    extra = 0
    max_num = 5
    fields = ('game_name', 'platform', 'desc_text')

    def get_queryset(self, request):
        print(request)
        print(self)
        return super().get_queryset(request)


class NoticeCfgAdmin(admin.ModelAdmin):
    list_display = ('desc_text',)

    fieldsets = [
        (None,               {'fields': ['desc_text', 'ssh', 'cdn']}),
    ]
    inlines = [GameInline]

class GameAdmin(admin.ModelAdmin):
    list_display = ('game_name', 'platform', 'desc_text')

    fieldsets = [
        ('INFO',             {'fields': ['game_name', 'sdk', 'platform', 'desc_text']}),
        ('URL Cfg',          {'fields': ['version_url', 'notice_url']}),
        ('noticeLink',       {'fields': ['noticeCfg']}),
    ]

admin.site.register(NoticeCfg, NoticeCfgAdmin)
admin.site.register(Game, GameAdmin)
admin.site.register(NoticeLog)
admin.site.register(SshCfg)
admin.site.register(CdnCfg)